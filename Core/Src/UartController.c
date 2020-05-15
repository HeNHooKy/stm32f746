/*
 * UartController.c
 *
 *  Created on: May 7, 2020
 *      Author: Митя
 */

#include "main.h"
#include "Parser.h"
#include "UartController.h"
#include "configuration.h"
#include "cmsis_os.h"


extern UART_HandleTypeDef huart6;
extern osSemaphoreId UCBinarySemHandle;
extern uint8_t Receive_2[6];
extern uint8_t Receive_4[8];


#ifdef __cplusplus
extern "C" {
#endif

//выделение памяти под список
struct Node queue[UC_QUEUE_SIZE]; //выделения памяти для очереди
unsigned int q_i = 0; //queue iterator

//контроль попыток
int attempt = 0;

int data; //дебаг инфа

//переменные и указатели
PNode Head = NULL;
PNode Tail = NULL;

//одинарный массив
uint8_t R[1] = {0x00}; //служит для проверка доставки сообщения об установке

//функции управления очередью

//добавляет новый запрос в очередь
void QueueAdd(unsigned int message, unsigned int group, unsigned int address, unsigned int command, unsigned int* answer, int* status)
{
	//ИСКЛЮЧИТЕЛЬНАЯ СИТУАЦИЯ. РАЗМЕР ОЧЕРЕДИ СТАЛ СЛИШКОМ БОЛЬШОЙ
	if (&queue[q_i] == Head)
	{
		return;
	}

	taskENTER_CRITICAL();
	{	//зарпещаем планировщику переключать процесс
		PNode elem = &queue[q_i];
		q_i++;  //реализуем кольцевой массив
		q_i = q_i < UC_QUEUE_SIZE ? q_i : 0;

		if (elem == NULL)
		{
			return;
		}

		elem->Next = NULL;
		//заполняем новый элемент
		elem->message = message;
		elem->group = group;
		elem->address = address;
		elem->answer = answer;
		elem->status = status;
		elem->command = command;

		elem->sost = UC_AWAIT; //устанавливаем состояния "ожидает"

		//обновляем состояние пользователя
		*elem->status = elem->sost;


		//КОНЕЦ ИСКЛЮЧИТЕЛЬНОЙ СИТУАЦИИ
		if (Tail == NULL)
		{
			Head = elem;
			Tail = Head;
		}
		else
		{
			Tail->Next = elem;
			Tail = elem;
		}
	}//завершение. Можно разрешить планировщику работать в привычном режиме
	taskEXIT_CRITICAL();
}

//удаляет элемент, на котором стоит текущий указатель
//перемещает указатель Head на следующий за ним элемент
void QueueDel()
{
    if (Head == NULL)
    {
        return;
    }

    if (Head == Tail)
    {
        Tail = NULL;
        Head = NULL;
        q_i = 0;
    }
    else
    {
        Head = Head->Next;
    }
}
//функции управления UART

//Отправляет сообщение message на указанный адрес address группы group
//для отслеживания состояния сообщения проверяйте переменную status
//в неё будет занесено состояние передачи сообщения
void UC_SEND_Message()
{
	uint8_t* message;
	uint8_t size;

	//т.к. иных груп вызвано быть не может, исключения не обрабатываются
	if(Head->group == GROUP_M)
	{	//парсит сообщение
		message = GX_MEM_Parse(Head->address, Head->message);
		size = SIZE_M;
	}
	else if(Head->group == GROUP_D)
	{
		message = GX_DECIMICAL_Parse(Head->address, Head->message);
		size = SIZE_D2;
	}

	while((attempt < 3 && Head->sost == UC_SENDING) || (Head->sost == UC_CON_SUM_ERR && attempt < 5))
	{
		if(Head->sost == UC_CON_SUM_ERR)
		{	//если не сходится контрольная сумма, ставим режим отправки
			Head->sost = UC_SENDING;

			//обновляем состояние пользователя
			*Head->status = Head->sost;
		}

		//передача сообщения
		attempt = attempt + 1;
		HAL_UART_Transmit_IT(&huart6, message, size);

		if(Head->sost == UC_SENDING)
		{	//если ответ вдруг уже пришел, ждать не нужно
			osDelay(UC_DELAY);
		}

	}

	if(Head->sost == UC_SENDING)
	{	//если ответ так и не был получен, ставим
		Head->sost = UC_SENDING_ERR;

		//обновляем состояние пользователя
		*Head->status = Head->sost;
	}
}

//Посылает запрос на указанный адрес и возвращает ответ в переменную answer
//проверить состояние передачи можно обратившись к переменной status
void UC_SEND_Request()
{
	uint8_t* message;
	uint8_t size = SIZE_REQUEST;

	//т.к. иных груп вызвано быть не может, исключения не обрабатываются
	if(Head->group == GROUP_M)
	{	//парсит сообщение
		message = GX_MEM_Request(Head->address);

	}
	else if(Head->group == GROUP_D)
	{
		message = GX_DECIMICAL_Request(Head->address);
	}

	while((attempt < 3 && Head->sost == UC_SENDING) || (Head->sost == UC_CON_SUM_ERR && attempt < 5))
	{
		if(Head->sost == UC_CON_SUM_ERR)
		{	//если не сходится контрольная сумма, ставим режим отправки
			Head->sost = UC_SENDING;

			//обновляем состояние пользователя
			*Head->status = Head->sost;
		}

		//передача сообщения
		attempt = attempt + 1;
		HAL_UART_Transmit_IT(&huart6, message, size);

		if(Head->sost == UC_SENDING)
		{	//если ответ вдруг уже пришел, ждать не нужно
			osDelay(UC_DELAY);
		}
	}

	if(Head->sost == UC_SENDING)
	{	//если ответ так и не был получен, ставим
		Head->sost = UC_SENDING_ERR;

		//обновляем состояние пользователя
		*Head->status = Head->sost;
	}

}

//добавляет указанный запрос в очередь, если это возможно
//message - сообщение (0-65535) - D | (0-1) - M
//group - группа адресов (GROUP_M|GROUP_D)
//address - адрес GX для записи сообщения
//command - комманда для отправки
//answer - адрес STM поля ответа
//status - адрес STM поля состояния
void UC_SEND(unsigned int message, unsigned int group, unsigned int address, unsigned int command, unsigned int* answer, int* status)
{
	QueueAdd(message, group, address, command, answer, status);
}

//Каждую итерацию проверяет возможность отправки запроса
//если это возможно, выполняет отправку запроса
void UC_Routine()
{   //задач нет
    if (Head == NULL)
    {
        return;
    }

    //если запрос выполнился - удалить
    if (Head->sost == UC_SENDED_OK || Head->sost == UC_SENDING_ERR)
    {
    	HAL_UART_Abort_IT(&huart6);
    	attempt = 0;
        QueueDel();
        return;
    }

    //если запрос выполняется - подождать
    if (Head->sost == UC_SENDING)
    {
        return;
    }

    //если запрос ожидает выполнения - выполнить
    if (Head->sost == UC_AWAIT)
    {
    	//сообщение отправлено на передачу
    	Head->sost = UC_SENDING;

    	//обновляем состояние пользователя
    	*Head->status = Head->sost;

        if (Head->command == UC_REQUEST)
        {
        	if(Head->group == GROUP_D)
			{	//запуск прослушки канала
				HAL_UART_Receive_IT(&huart6, Receive_4, 8);
			}
			else if(Head->group == GROUP_M)
			{	//запуск прослушки канала
				HAL_UART_Receive_IT(&huart6, Receive_2, 6);
			}
        	//отправка запроса
            UC_SEND_Request();
        }
        else if (Head->command == UC_SET)
        {	//запуск прослушки канала
        	HAL_UART_Receive_IT(&huart6, R, 1);
        	//отправка сообщения
            UC_SEND_Message();
        }
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);

	if(Head->command == UC_REQUEST)
	{
		int data;
		if(Head->group == GROUP_D)
		{
			data = GX_DECIMICAL_Unparse();
			if(data == GX_ERR_CONTROL_SUM)
			{	//контрольная сумма не сошлась
				Head->sost = UC_CON_SUM_ERR;

				//обновляем состояние пользователя
				*Head->status = Head->sost;

				HAL_UART_Receive_IT(huart, Receive_4, 8);
				return;
			}
			else
			{
				*Head->answer = data;
			}
		}
		else if(Head->group == GROUP_M)
		{
			data = GX_MEM_Unparse(Head->address);
			if(data == GX_ERR_CONTROL_SUM)
			{	//контрольная сумма не сошлась
				Head->sost = UC_CON_SUM_ERR;

				//обновляем состояние пользователя
				*Head->status = Head->sost;

				HAL_UART_Receive_IT(huart, Receive_2, 6);
				return;
			}
			else
			{
				*Head->answer = data;
			}
		}
	}
	Head->sost = UC_SENDED_OK;

	//обновляем состояние пользователя
	*Head->status = Head->sost;
}

#ifdef __cplusplus
}
#endif




