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
	taskENTER_CRITICAL();
	{	//зарпещаем планировщику переключать процесс
		PNode elem = &queue[q_i];
		q_i = q_i + 1;
		if (elem == NULL)
		{
			return;
		}
		//заполняем новый элемент
		elem->message = message;
		elem->group = group;
		elem->address = address;
		elem->answer = answer;
		elem->status = status;
		elem->command = command;

		*elem->status = UC_AWAIT; //устанавливаем состояния "ожидает"

		if (Head == NULL)
		{
			Head = elem;
			Tail = elem;
			elem->Next = NULL;
		}
		else
		{
			Tail->Next = elem;
			Tail = elem;
			Tail->Next = NULL;
		}
		data = *Head->status;
	}//завершение. Можно разрешить планировщику работать в привычном режиме
	taskEXIT_CRITICAL();
}

//удаляет элемент, на котором стоит текущий указатель
//перемещает указатель Head на следующий за ним элемент
void QueueDel()
{
    if (Head == Tail)
    {
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->Next;
    }
    q_i--;
}

//функции управления UART

//Отправляет сообщение message на указанный адрес address группы group
//для отслеживания состояния сообщения проверяйте переменную status
//в неё будет занесено состояние передачи сообщения
void UC_SEND_Message()
{
	uint8_t* message;
	if(Head->group == GROUP_M)
	{	//парсит сообщение и передает его в
		message = GX_MEM_Parse(Head->address, Head->message);
		HAL_UART_Transmit_IT(&huart6, message, SIZE_M);
	}
	else if(Head->group == GROUP_D)
	{
		message = GX_DECIMICAL_Parse(Head->address, Head->message);
		HAL_UART_Transmit_IT(&huart6, message, SIZE_D2);
	}
}

//Посылает запрос на указанный адрес и возвращает ответ в переменную answer
//проверить состояние передачи можно обратившись к переменной status
void UC_SEND_Request()
{
	uint8_t* message;
	if(Head->group == GROUP_M)
	{
		message = GX_MEM_Request(Head->address);
		HAL_UART_Transmit_IT(&huart6, message, SIZE_M);
	}
	else if(Head->group == GROUP_D)
	{
		message = GX_DECIMICAL_Request(Head->address);
		HAL_UART_Transmit_IT(&huart6, message, SIZE_D2);
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

    if (*Head->status == UC_SENDED_OK || *Head->status == UC_SENDING_ERR)
    {
    	attempt = 0;
        QueueDel();
        return;
    }

    if (*Head->status == UC_SENDING)
    {
        return;
    }

    if (*Head->status == UC_AWAIT)
    {
        if (Head->command == UC_REQUEST)
        {
            UC_SEND_Request();
        }
        else if (Head->command == UC_SET)
        {
            UC_SEND_Message();
        }
    }
}


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	attempt = attempt + 1;

	if(Head->command == UC_REQUEST)
	{
		if(Head->group == GROUP_D)
		{
			if((HAL_UART_Receive_IT(huart, Receive_4, 8) != HAL_OK) && attempt < 3)
			{
				UC_SEND_Request();
			}
		}
		else if(Head->group == GROUP_M)
		{
			if((HAL_UART_Receive_IT(huart, Receive_2, 6) != HAL_OK) && attempt < 3)
			{
				UC_SEND_Request();
			}
		}
	}
	else
	{
		if((HAL_UART_Receive_IT(huart, R, 1) != HAL_OK) && attempt < 3)
		{
			UC_SEND_Message();
		}
	}
	if(attempt >= 2)
	{
		*Head->status = UC_SENDING_ERR;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(Head->command == UC_REQUEST)
	{
		int data = 0;

		if(Head->group == GROUP_D)
		{
			data = GX_DECIMICAL_Unparse();
		}
		else if(Head->group == GROUP_M)
		{
			data = GX_MEM_Unparse(Head->address);
		}

		if(data != GX_ERR_CONTROL_SUM)
		{
			*Head->answer = data;
		}
		else
		{
			UC_SEND_Request();
			return;
		}
	}
	*Head->status = UC_SENDED_OK;
}

#ifdef __cplusplus
}
#endif




