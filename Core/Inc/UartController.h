/*
 * UartController.h
 *
 *  Created on: May 7, 2020
 *      Author: Митя
 */


#ifndef INC_UARTCONTROLLER_H_
#define INC_UARTCONTROLLER_H_
#ifdef __cplusplus
extern "C" {
#endif

#define UC_QUEUE_SIZE 100 //максимальное количество заросов единовремено
#define UC_DELAY 0xFFFF //промежуток между повторными отправками сообщений

//состояния отправки сообщений
#define UC_SENDED_OK 0 //сообщений доставлено, ошибок не возникло
#define UC_SENDING 1 //сообщение отправляется прямо сейчас
#define UC_AWAIT 2 //сообщений ждет своей очереди

//команды
#define UC_REQUEST 0 //команда запроса состояния по выделеному адресу
#define UC_SET 1 //команда установки состояния на выделенный адрес

//ошибки
#define UC_SENDING_ERR 10 //сообщений не доставлено. Возникли ошибки на линии связи
//может возникнуть из-за серьезных помех на линии связи
//или при отсутствии ответа от контроллера

struct Node
{
	//возвращаемые значения
	unsigned int* answer; //указатель на адрес поля ответа
	int* status; //указатель на адрес поля состояния

	//отправляемые значения
	unsigned int message; //сообщение (0-65535) - D | (0-1) - M
	unsigned int group; //группа адресов (M|D)
	unsigned int address; //адрес для записи сообщения
	unsigned int command; //комманда для отправки

	struct Node* Next; // указатель следущий  элемент
};
typedef struct Node* PNode; // указатель на вершину

//функции управления очередью
void QueueAdd(unsigned int message, unsigned int group, unsigned int address, unsigned int command, unsigned int* answer, int* status);
void QueueDel();

//функции отправки сообщений по UART
void UC_SEND_Message();
void UC_SEND_Request();

//ВНЕШНИЕ ФУНКЦИИ

//добавляет указанный запрос в очередь, если это возможно
//message - сообщение (0-65535) - D | (0-1) - M
//group - группа адресов (GROUP_M|GROUP_D)
//address - адрес GX для записи сообщения
//command - комманда для отправки
//answer - адрес STM поля ответа
//status - адрес STM поля состояния
void UC_SEND(unsigned int message, unsigned int group, unsigned int command, unsigned int address, unsigned int* answer, int* satus);

void UC_Routine();
void UC_Received();
void UC_Transmited();

#ifdef __cplusplus
}
#endif

#endif /* INC_UARTCONTROLLER_H_ */
