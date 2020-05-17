/*
 * DryEvent.c
 *
 *  Created on: May 12, 2020
 *      Author: Митя
 */


#include "main.h"
#include "DryEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

//итераторы массивов событий
int sundayID = -1; //id воскресений
int mondayID = -1; //id понедельников
int tuesdayID = -1; //id вторников
int wednesdayID = -1; //id сред
int thursdayID = -1;//id четвергов
int fridayID = -1;//id пятниц
int saturdayID = -1;//id суббот

//массивы событий
struct dryEvent sundayEvents[MAX_EVENTS];;
struct dryEvent mondayEvents[MAX_EVENTS];
struct dryEvent tuesdayEvents[MAX_EVENTS];
struct dryEvent wednesdayEvents[MAX_EVENTS];
struct dryEvent thursdayEvents[MAX_EVENTS];
struct dryEvent fridayEvents[MAX_EVENTS];
struct dryEvent saturdayEvents[MAX_EVENTS];


//добавляет событие сушки на указанный день, в указанное время, с указанной длительностью и температурой
int AddDryEvent(int day, int hour, int minut, int duration_F, int temp_F, int duration_S, int temp_S)
{
	if (day < 0 || day > 6)
	{
		return EVENT_ERR_DAY_NOT_EXISTS; //ошибка - такого дня не существует
	}

	switch (day)
	{
	case Sunday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (sundayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			sundayID = sundayID + 1;
			SetUpEvent(sundayEvents, sundayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	case Monday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (mondayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			mondayID = mondayID + 1;
			SetUpEvent(mondayEvents, mondayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	case Tuesday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (tuesdayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			tuesdayID = tuesdayID + 1;
			SetUpEvent(tuesdayEvents, tuesdayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	case Wednesday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (wednesdayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			wednesdayID = wednesdayID + 1;
			SetUpEvent(wednesdayEvents, wednesdayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	case Thursday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (thursdayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			thursdayID = thursdayID + 1;
			SetUpEvent(thursdayEvents, thursdayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	case Friday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (fridayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			fridayID = fridayID + 1;
			SetUpEvent(fridayEvents, fridayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	case Saturday:
		if (IsMayAdded(day, hour, minut, duration_F, duration_S))
		{
			if (saturdayID >= MAX_EVENTS - 1)
			{
				return EVENT_NO;
			}
			saturdayID = saturdayID + 1;
			SetUpEvent(saturdayEvents, saturdayID, day, hour, minut, duration_F, temp_F, duration_S, temp_S);
			return EVENT_OK;
		}
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
	return EVENT_NO;
}

//удаляет указанное событие из массива определенного дня
int DelDryEvent(int day, int id)
{
	if (id < 0 && id > 9)
	{
		return EVENT_ERR_ID_NOT_EXISTS;
	}

	switch (day)
	{
	case Sunday:
		SetDownEvent(sundayEvents, sundayID, id);
		sundayID = sundayID - 1;
		break;
	case Monday:
		SetDownEvent(mondayEvents, mondayID, id);
		mondayID = mondayID - 1;
		break;
	case Tuesday:
		SetDownEvent(tuesdayEvents, tuesdayID, id);
		tuesdayID = tuesdayID - 1;
		break;
	case Wednesday:
		SetDownEvent(wednesdayEvents, wednesdayID, id);
		wednesdayID = wednesdayID - 1;
		break;
	case Thursday:
		SetDownEvent(thursdayEvents, thursdayID, id);
		thursdayID = thursdayID - 1;
		break;
	case Friday:
		SetDownEvent(fridayEvents, fridayID, id);
		fridayID = fridayID - 1;
		break;
	case Saturday:
		SetDownEvent(saturdayEvents, saturdayID, id);
		saturdayID = saturdayID - 1;
		break;
	default:
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
	return EVENT_OK;
}

//проверяет необходимость вызова события какого либо события
//возвращает EVENT_AWAY - действий не требуется
//возвращает 0-9 - необходимо вызвать соответствующее событие
int IsNeedExecuteEventID(int day, int hour, int minut)
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
int IsMayAdded(int day, int hour, int minut, int duration_F, int duration_S)
{
	int thisTimeStart = AbsoluteTime((day*24*6) + (hour * 60) + minut);
	int thisTimeEnd = AbsoluteTime(thisTimeStart + GetMax(duration_F, duration_S));

	//ДА ПРОСТИТ МЕНЯ ГОСПОДЬ БОХ
	if (ProcesCycle(sundayEvents, sundayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	if (ProcesCycle(mondayEvents, mondayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	if (ProcesCycle(tuesdayEvents, tuesdayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	if (ProcesCycle(wednesdayEvents, wednesdayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	if (ProcesCycle(thursdayEvents, thursdayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	if (ProcesCycle(fridayEvents, fridayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	if (ProcesCycle(saturdayEvents, saturdayID, thisTimeStart, thisTimeEnd))
	{
		return 0;
	}

	return 1; //проверки пройдены успешно
}

//цикл обхода каждого массива
int ProcesCycle(struct dryEvent* dayArray, int dayID, int timeStart, int timeEnd)
{
	int anyTimeStart;
	int anyTimeEnd;
	for (int i = 0; i <= dayID; i = i + 1)
	{
		anyTimeStart = AbsoluteTime((dayArray[i].startDay*24*60) + (dayArray[i].startHour * 60) + dayArray[i].startMinut);
		anyTimeEnd = AbsoluteTime(anyTimeStart + GetMax(dayArray[i].duration_F, dayArray[i].duration_S));

		if ((anyTimeStart >= timeStart && anyTimeStart <= timeEnd) ||
			(anyTimeEnd >= timeStart && anyTimeEnd <= timeEnd) ||
			(timeStart >= anyTimeStart && timeStart <= anyTimeEnd) ||
			(timeEnd >= anyTimeStart && timeEnd <= anyTimeEnd))
		{
			return 1;
		}
	}
	return 0;
}

//заносит все данные в массив
void SetUpEvent(struct dryEvent* dayArray, int id, int day, int hour, int minut, int duration_F, int temp_F, int duration_S, int temp_S)
{
	dayArray[id].id = id;
	dayArray[id].startDay = day;
	dayArray[id].startHour = hour;
	dayArray[id].startMinut = minut;
	dayArray[id].duration_F = duration_F;
	dayArray[id].temp_F = temp_F;
	dayArray[id].duration_S = duration_S;
	dayArray[id].temp_S = temp_S;
}

//делает сдвиг массива данных "влево" направленный на id
void SetDownEvent(struct dryEvent* dayArray, int dayID, int id)
{
	dayArray[id].id = -1;
	dayArray[id].startDay = -1;
	dayArray[id].startHour = -1;
	dayArray[id].startMinut = -1;

	for (int i = id; i < dayID; i = i + 1)
	{
		dayArray[i].id = dayArray[i + 1].id;
		dayArray[i].startDay = dayArray[i + 1].startDay;
		dayArray[i].startHour = dayArray[i + 1].startHour;
		dayArray[i].startMinut = dayArray[i + 1].startMinut;
		dayArray[i].duration_F = dayArray[i + 1].duration_F;
		dayArray[i].temp_F = dayArray[i + 1].temp_F;
		dayArray[i].duration_S = dayArray[i + 1].duration_S;
		dayArray[i].temp_S = dayArray[i + 1].temp_S;
	}
}

//возвращает id если событие с такими параметрами существует: EVENT_AWAY или id
int ExecuteChecker(struct dryEvent* dayArray, int dayID, int day, int hour, int minut)
{

	for (int i = 0; i <= dayID; i = i + 1)
	{
		if (dayArray[i].startDay == day && dayArray[i].startHour == hour && dayArray[i].startMinut == minut)
		{
			return dayArray[i].id;
		}
	}
	return EVENT_AWAY;
}

//возвращает больший элемент из двух принятых
int GetMax(int a, int b)
{
	if (a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//получение длительности соответствующего события
int GetDurationEvent_F(int day, int id)
{
	if (id < 0 || id > MAX_EVENTS)
	{
		return EVENT_ERR_ID_NOT_EXISTS;
	}

	struct dryEvent* dayArray = GetPointerArray(day);
	if (dayArray != NULL)
	{
		return dayArray[id].duration_F;
	}
	else
	{
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
}

//получение температуры соответствующего события
int GetTempEvent_F(int day, int id)
{
	if (id < 0 || id > MAX_EVENTS)
	{
		return EVENT_ERR_ID_NOT_EXISTS;
	}

	struct dryEvent* dayArray = GetPointerArray(day);
	if (dayArray != NULL)
	{
		return dayArray[id].temp_F;
	}
	else
	{
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
}

//получение длительности соответствующего события
int GetDurationEvent_S(int day, int id)
{
	if (id < 0 || id > MAX_EVENTS)
	{
		return EVENT_ERR_ID_NOT_EXISTS;
	}

	struct dryEvent* dayArray = GetPointerArray(day);
	if (dayArray != NULL)
	{
		return dayArray[id].duration_S;
	}
	else
	{
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
}

//получение температуры соответствующего события
int GetTempEvent_S(int day, int id)
{
	if (id < 0 || id > MAX_EVENTS)
	{
		return EVENT_ERR_ID_NOT_EXISTS;
	}

	struct dryEvent* dayArray = GetPointerArray(day);
	if (dayArray != NULL)
	{
		return dayArray[id].temp_S;
	}
	else
	{
		return EVENT_ERR_DAY_NOT_EXISTS;
	}
}

//делате время абсолютным
int AbsoluteTime(int time)
{
	return (time + TIME_ABSOLUTE) % TIME_ABSOLUTE;
}

//возващает указатель на выбранный массив
struct dryEvent* GetPointerArray(int day)
{
	switch (day)
	{
	case Sunday:
		return sundayEvents;
		break;
	case Monday:
		return mondayEvents;
		break;
	case Tuesday:
		return tuesdayEvents;
		break;
	case Wednesday:
		return wednesdayEvents;
		break;
	case Thursday:
		return thursdayEvents;
		break;
	case Friday:
		return fridayEvents;
		break;
	case Saturday:
		return saturdayEvents;
		break;
	default:
		return NULL;
	}
}

#ifdef __cplusplus
}
#endif
