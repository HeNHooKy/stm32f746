/*
 * DryEvent.c
 *
 *  Created on: May 12, 2020
 *      Author: Митя
 */


#include "main.h"
#include "DryEvent.h"

//итераторы массивов событий
uint8_t sundayID = 0; //id воскресений
uint8_t mondayID = 0; //id понедельников
uint8_t tuesdayID = 0; //id вторников
uint8_t wednesdayID = 0; //id сред
uint8_t thursdayID = 0;//id четвергов
uint8_t fridayID = 0;//id пятниц
uint8_t saturdayID = 0;//id суббот

//массивы событий
struct dryEvent sundayEvents[MAX_EVENTS];
struct dryEvent mondayEvents[MAX_EVENTS];
struct dryEvent tuesdayEvents[MAX_EVENTS];
struct dryEvent wednesdayEvents[MAX_EVENTS];
struct dryEvent thursdayEvents[MAX_EVENTS];
struct dryEvent fridayEvents[MAX_EVENTS];
struct dryEvent saturdayEvents[MAX_EVENTS];


//добавляет событие сушки на указанный день, в указанное время, с указанной длительностью и температурой
int AddDryEvent(uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration, uint8_t temp)
{
	if (day < 0 || day > 6)
	{
		return EVENT_ERR_DAY_NOT_EXISTS; //ошибка - такого дня не существует
	}

	switch (day)
	{
	case Sunday:
		if (IsMayAdded(sundayEvents, sundayID, day, hour, minut, duration))
		{
			SetUpEvent(sundayEvents, sundayID, day, hour, minut, duration, temp);
			sundayID = sundayID + 1;
		}
		break;
	case Monday:
		if (IsMayAdded(mondayEvents, mondayID, day, hour, minut, duration))
		{
			SetUpEvent(mondayEvents, mondayID, day, hour, minut, duration, temp);
			mondayID = mondayID + 1;
		}
		break;
	case Tuesday:
		if (IsMayAdded(tuesdayEvents, tuesdayID, day, hour, minut, duration))
		{
			SetUpEvent(tuesdayEvents, tuesdayID, day, hour, minut, duration, temp);
			tuesdayID = tuesdayID + 1;
		}
		break;
	case Wednesday:
		if (IsMayAdded(wednesdayEvents, wednesdayID, day, hour, minut, duration))
		{
			SetUpEvent(wednesdayEvents, wednesdayID, day, hour, minut, duration, temp);
			wednesdayID = wednesdayID + 1;
		}
		break;
	case Thursday:
		if (IsMayAdded(thursdayEvents, thursdayID, day, hour, minut, duration))
		{
			SetUpEvent(thursdayEvents, thursdayID, day, hour, minut, duration, temp);
			thursdayID = thursdayID + 1;
		}
		break;
	case Friday:
		if (IsMayAdded(fridayEvents, fridayID, day, hour, minut, duration))
		{
			SetUpEvent(fridayEvents, fridayID, day, hour, minut, duration, temp);
			fridayID = fridayID + 1;
		}
		break;
	case Saturday:
		if (IsMayAdded(saturdayEvents, saturdayID, day, hour, minut, duration))
		{
			SetUpEvent(saturdayEvents, saturdayID, day, hour, minut, duration, temp);
			saturdayID = saturdayID + 1;
		}
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
	return EVENT_OK;
}

//удаляет указанное событие из массива определенного дня
int DelDryEvent(uint8_t day, uint8_t id)
{
	if (id < 0 && id > 9)
	{
		return EVENT_ERR_ID_NOT_EXISTS;
	}

	switch (day)
	{
	case Sunday:
		SetDownEvent(sundayEvents, sundayID, id);
		break;
	case Monday:
		SetDownEvent(mondayEvents, mondayID, id);
		break;
	case Tuesday:
		SetDownEvent(tuesdayEvents, tuesdayID, id);
		break;
	case Wednesday:
		SetDownEvent(wednesdayEvents, wednesdayID, id);
		break;
	case Thursday:
		SetDownEvent(thursdayEvents, thursdayID, id);
		break;
	case Friday:
		SetDownEvent(fridayEvents, fridayID, id);
		break;
	case Saturday:
		SetDownEvent(saturdayEvents, saturdayID, id);
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
	return EVENT_OK;
}

//проверяет необходимость вызова события какого либо события
//возвращает EVENT_AWAY - действий не требуется
//возвращает 0-9 - необходимо вызвать соответствующее событие
int IsNeedExecuteEventID(uint8_t day, uint8_t hour, uint8_t minut)
{
	switch (day)
	{
	case Sunday:
		return ExecuteChecker(sundayEvents, sundayID, day, hour, minut);
		break;
	case Monday:
		return ExecuteChecker(mondayEvents, mondayID, day, hour, minut);
		break;
	case Tuesday:
		return ExecuteChecker(tuesdayEvents, tuesdayID, day, hour, minut);
		break;
	case Wednesday:
		return ExecuteChecker(wednesdayEvents, wednesdayID, day, hour, minut);
		break;
	case Thursday:
		return ExecuteChecker(thursdayEvents, thursdayID, day, hour, minut);
		break;
	case Friday:
		return ExecuteChecker(fridayEvents, fridayID, day, hour, minut);
		break;
	case Saturday:
		return ExecuteChecker(saturdayEvents, saturdayID, day, hour, minut);
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
	return EVENT_AWAY;
}


//возращает 0 - если событие невозможно добавить в указанный массив
//и единицу в противном случае
int IsMayAdded(struct dryEvent* dayArray, uint8_t max, uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration)
{
	if (max + 1 >= MAX_EVENTS)
	{
		return 0;
	}

	uint8_t thisTimeStart = minut + (hour * 60) - DIFFERENCE;
	uint8_t thisTimeEnd = thisTimeStart + duration + DIFFERENCE;

	uint8_t anyTimeStart = 0;
	uint8_t anyTimeEnd = 0;

	for (uint8_t i = 0; i <= max; i = i + 1)
	{
		anyTimeStart = (dayArray[i].startHour * 60) + (dayArray[i].startMinut);
		anyTimeEnd = anyTimeStart + dayArray[i].duration;

		if ((anyTimeStart > thisTimeStart && anyTimeStart < thisTimeEnd) ||
			(anyTimeEnd > thisTimeStart && anyTimeEnd < thisTimeEnd) ||
			(thisTimeStart > anyTimeStart && thisTimeStart < anyTimeEnd) ||
			(thisTimeEnd > anyTimeStart && thisTimeEnd < anyTimeEnd))
		{
			return 0;
		}
	}
	return 1;
}

//заносит все данные в массив
void SetUpEvent(struct dryEvent* dayArray, uint8_t id, uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration, uint8_t temp)
{
	dayArray[id].id = id;
	dayArray[id].startDay = day;
	dayArray[id].startHour = hour;
	dayArray[id].startMinut = minut;
	dayArray[id].duration = duration;
	dayArray[id].temp = temp;
}

//делает сдвиг массива данных "влево" направленный на id
void SetDownEvent(struct dryEvent* dayArray, uint8_t dayID, uint8_t id)
{
	for (uint8_t i = id; i < dayID; i = i + 1)
	{
		dayArray[i].id = dayArray[i + 1].id;
		dayArray[i].startDay = dayArray[i + 1].startDay;
		dayArray[i].startHour = dayArray[i + 1].startHour;
		dayArray[i].startMinut = dayArray[i + 1].startMinut;
		dayArray[i].duration = dayArray[i + 1].duration;
		dayArray[i].temp = dayArray[i + 1].temp;
	}
}

//проверяет что нужно возвращать IsNeedExecuteEvent: EVENT_AWAY или id
int ExecuteChecker(struct dryEvent* dayArray, uint8_t dayID, uint8_t day, uint8_t hour, uint8_t minut)
{

	for (uint8_t i = 0; i <= dayID; i = i + 1)
	{
		if (dayArray[i].startDay == day && dayArray[i].startHour == hour && dayArray[i].startMinut == minut)
		{
			return dayArray[i].id;
		}
	}
	return -1;
}

//получение длительности соответствующего события
uint8_t GetDurationEvent(uint8_t day, uint8_t id)
{
	switch (day)
	{
	case Sunday:
		return sundayEvents[id].duration;
		break;
	case Monday:
		return mondayEvents[id].duration;
		break;
	case Tuesday:
		return tuesdayEvents[id].duration;
		break;
	case Wednesday:
		return wednesdayEvents[id].duration;
		break;
	case Thursday:
		return thursdayEvents[id].duration;
		break;
	case Friday:
		return fridayEvents[id].duration;
		break;
	case Saturday:
		return saturdayEvents[id].duration;
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
}

//получение температуры соответствующего события
uint8_t GetTempEvent(uint8_t day, uint8_t id)
{
	switch (day)
	{
	case Sunday:
		return sundayEvents[id].temp;
		break;
	case Monday:
		return mondayEvents[id].temp;
		break;
	case Tuesday:
		return tuesdayEvents[id].temp;
		break;
	case Wednesday:
		return wednesdayEvents[id].temp;
		break;
	case Thursday:
		return thursdayEvents[id].temp;
		break;
	case Friday:
		return fridayEvents[id].temp;
		break;
	case Saturday:
		return saturdayEvents[id].temp;
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
}
