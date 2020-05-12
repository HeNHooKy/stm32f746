/*
 * DryEvent.c
 *
 *  Created on: May 12, 2020
 *      Author: Митя
 */


#include "main.h"
#include "DryEvent.h"


//Рабочие переменные
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
	if(day < 0 || day > 6)
	{
		return -1; //ошибка - такого дня не существует
	}

	switch (day)
	{
	case Sunday:
		if(IsMayAdded(sundayEvents, sundayID, day, hour, minut, duration))
		{
			SetUpEvent(sundayEvents, sundayID, day, hour, minut, duration, temp);
			sundayID = sundayID + 1;
		}
		break;
	case Monday:
		if(IsMayAdded(mondayEvents, mondayID, day, hour, minut, duration))
		{
			SetUpEvent(mondayEvents, mondayID, day, hour, minut, duration, temp);
			mondayID = mondayID + 1;
		}
		break;
	case Tuesday:
		if(IsMayAdded(tuesdayEvents, tuesdayID, day, hour, minut, duration))
		{
			SetUpEvent(tuesdayEvents, tuesdayID, day, hour, minut, duration, temp);
			tuesdayID = tuesdayID + 1;
		}
		break;
	case Wednesday:
		if(IsMayAdded(wednesdayEvents, wednesdayID, day, hour, minut, duration))
		{
			SetUpEvent(wednesdayEvents, wednesdayID, day, hour, minut, duration, temp);
			wednesdayID = wednesdayID + 1;
		}
		break;
	case Thursday:
		if(IsMayAdded(thursdayEvents, thursdayID, day, hour, minut, duration))
		{
			SetUpEvent(thursdayEvents, thursdayID, day, hour, minut, duration, temp);
			thursdayID = thursdayID + 1;
		}
		break;
	case Friday:
		if(IsMayAdded(fridayEvents, fridayID, day, hour, minut, duration))
		{
			SetUpEvent(fridayEvents, fridayID, day, hour, minut, duration, temp);
			fridayID = fridayID + 1;
		}
		break;
	case Saturday:
		if(IsMayAdded(saturdayEvents, saturdayID, day, hour, minut, duration))
		{
			SetUpEvent(saturdayEvents, saturdayID, day, hour, minut, duration, temp);
			saturdayID = saturdayID + 1;
		}
		break;
	default:
		return -1;
	}
}

//удаляет указанный
int DelDryEvent(uint8_t day, uint8_t id)
{
	if(id < 0 && id > 9)
	{
		return -1;
	}


}

//возращает 0 - если событие невозможно добавить в указанный массив
//и единицу в противном случае
int IsMayAdded(struct dryEvent* dayArray, uint8_t max, uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration)
{
	if (max + 1 >= MAX_EVENTS)
	{
		return 0;
	}

	uint8_t thisTimeStart = minut + (hour * 60);
	uint8_t thisTimeEnd = thisTimeStart + duration;

	uint8_t anyTimeStart = 0;
	uint8_t anyTimeEnd = 0;

	for (uint8_t i = 0; i < max; i++)
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




