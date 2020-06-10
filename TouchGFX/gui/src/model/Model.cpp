#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "UartController.h"
#include "configuration.h"
#include "cmsis_os.h"
#include "main.h"
#include <string>

unsigned int trash = 0; //"мусорная" переменная. В эту переменную можно записывать любые данные.

//семафор контроля обновления данных
extern osSemaphoreId InformationUpdateSemHandle;

//флаг управления сушки по расписанию
extern int isBeingWorking;

//проверка на отображение требования пройти сервисное обслуживание
extern int answerServices;

//адреса для отображения данных на экране и проверки статуса
extern int statusAddressLeft; //адрес работающего режима левого отсека

extern int statusAddressRight; //адрес работающего режима правого отсека

extern unsigned int tempLeft; //состояние температуры в левом отсеке
extern int statusTL; //состояние ответа о температуре в левом отсеке

extern unsigned int tempRight; //состояние температуры в левом отсеке
extern int statusRT; //состояние ответа о температуре в правом отсеке

extern unsigned int timeLeft; //состояние времени в левом отсеке
extern int statusTiL; //состояние ответа о времени в левом отсеке

extern unsigned int timeRight; //состояние времени в правом отсеке
extern int statusTiR; //состояние ответа о времени в правом отсеке

extern unsigned int statusLeft; //состояние работы левого отсека
extern int statusSL; //состояние ответа о работе левого отсека

extern unsigned int statusRight; //состояние работы правого отсека
extern int statusSR; //состояние ответа о работе правого отсека

extern int GoToMain; //необходимость перейти на main screen


int setLeftTempStatus = 0;
int setLeftTimeStatus = 0;
int setLeftOnStatus = 0;
int setLeftOffStatus = 0;

int setRightTempStatus = 0;
int setRightTimeStatus = 0;
int setRightOnStatus = 0;
int setRightOffStatus = 0;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{	//каждый такт

	if(GoToMain && !CheckTimeDate())
	{
		GoToMain = false;
		modelListener->GoToMain();
	}

	//обновим данные о времени
	DisplayTime();
	//отображение восклицательного знака
	modelListener->DisplayServiceMaintenance(answerServices);
	//обновление данных сушки
	if((xSemaphoreTake(InformationUpdateSemHandle, (TickType_t) 10)) == pdTRUE)
	{
		if(statusTL == UC_SENDED_OK)
		{	//отправка текущей температуры в левом отсеке
			modelListener->DisplayTempLeft(tempLeft);
		}

		if(statusRT == UC_SENDED_OK)
		{	//отправка текущей температуры в правом отсеке
			modelListener->DisplayTempRight(tempRight);
		}

		if(statusTiL == UC_SENDED_OK)
		{	//отправка текущего времени в левом отсеке
			modelListener->DisplayTimeLeft(timeLeft);
		}

		if(statusTiR == UC_SENDED_OK)
		{	//отправка текущего времени в правом отсеке
			modelListener->DisplayTimeRight(timeRight);
		}



		//СЛОЖНЫЙ БЛОК
		if(statusSL == UC_SENDED_OK)
		{	//отправка текущего состояния в левом отсеке
			modelListener->DisplayStatusLeft(statusLeft);
		}

		if(statusSR == UC_SENDED_OK)
		{   //отправка текущего состояния в правом отсеке
			modelListener->DisplayStatusRight(statusRight);
		}

		if(statusSR == UC_SENDING_ERR)
		{	//нет ответа от GX
			statusSR = UC_NO_MESSAGE;
			statusAddressRight = NULL_ADDRESS;	//отправляем сообщение на экран
			modelListener->ShowMessage(2);
		}

		if(statusSL == UC_SENDING_ERR)
		{	//нет ответа от GX
			statusSL = UC_NO_MESSAGE;
			statusAddressLeft = NULL_ADDRESS;	//отправляем сообщение на экран
			modelListener->ShowMessage(2);
		}
	}
}

void Model::SendLeftTemp(int value)
{
	//в данном случа проверка ответа не требуется
	UC_SEND(value, GROUP_D, ADDRESS_TEMP_LEFT_OUT, UC_SET, &trash, &setLeftTempStatus);
}

void Model::SendLeftTime(int value)
{
	//в данном случа проверка ответа не требуется
	UC_SEND(value, GROUP_D, ADDRESS_TIME_LEFT_OUT, UC_SET, &trash, &setLeftTimeStatus);
}

void Model::SendLeftOn(int address)
{
	//в данном случа проверка ответа не требуется
	statusLeft = 1;
	statusAddressLeft = address;
	UC_SEND(SET_M, GROUP_M, address, UC_SET, &trash, &setLeftOnStatus);
	UC_REQUESTER();
}

void Model::SendLeftOff(int address)
{
	statusLeft = 0;
	//в данном случа проверка ответа не требуется
	UC_SEND(FOLD_M, GROUP_M, address, UC_SET, &trash, &setLeftOffStatus);
	UC_REQUESTER();
}


void Model::SendRightTemp(int value)
{
	//в данном случа проверка ответа не требуется
	UC_SEND(value, GROUP_D, ADDRESS_TEMP_RIGHT_OUT, UC_SET, &trash, &setRightTempStatus);
}

void Model::SendRightTime(int value)
{
	//в данном случа проверка ответа не требуется
	UC_SEND(value, GROUP_D, ADDRESS_TIME_RIGHT_OUT, UC_SET, &trash, &setRightTimeStatus);
}

void Model::SendRightOn(int address)
{
	statusRight = 1;
	statusAddressRight = address;
	UC_SEND(SET_M, GROUP_M, address, UC_SET, &trash, &setRightOnStatus);
	UC_REQUESTER();
}

void Model::SendRightOff(int address)
{
	statusRight = 0;
	//в данном случа проверка ответа не требуется
	UC_SEND(FOLD_M, GROUP_M, address, UC_SET, &trash, &setRightOffStatus);
	UC_REQUESTER();
}

//часы, минуты, день от 1 до 7
void Model::SetClock(int hours, int minutes, int weekDay)
{
	SetTimeDate((uint8_t) hours, (uint8_t) minutes, (uint8_t) weekDay);
}

void Model::SetDryEventsFlag(bool flag)
{
	isBeingWorking = flag ? 1 : 0;
}


int Model::ClockChecker()
{
	return CheckTimeDate();
}

void Model::DisplayTime()
{	//обновляем данные о времени
	int day, hour, minute;
	GetTimeDate(&day, &hour, &minute);
	modelListener->DisplayCurrentTime(day, hour, minute);
}

void Model::GetCurTimeDay(int *day, int *hour, int *minute)
{
	GetTimeDate(day, hour, minute);
}
