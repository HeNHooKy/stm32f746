/*
 * DryEvent.h
 *
 *  Created on: May 12, 2020
 *      Author: Митя
 */

#ifndef INC_DRYEVENT_H_
#define INC_DRYEVENT_H_
#ifdef __cplusplus
extern "C" {
#endif

#define MAX_EVENTS 3

#define START_ADDRESS 200

#define DIFFERENCE 5 //минимальная разница между событиями

#define Sunday 0 //воскресенье
#define Monday 1 //понедельник
#define Tuesday 2 //вторник
#define Wednesday 3 //среда
#define Thursday 4 //четверг
#define Friday 5 //пятница
#define Saturday 6 //суббота

#define EVENT_ERR_DAY_NOT_EXISTS -2 //ошибки
#define EVENT_ERR_ID_NOT_EXISTS -3

#define EVENT_AWAY -1 // нет событий на вызов
#define EVENT_NO 0 //нельзя добавить новое событие
#define EVENT_OK 1 //действие успешно выполнено

#define TIME_ABSOLUTE 10080


struct dryEvent
{
	int id; //порядковый номер события
	int startDay; //Целое число - день недели [0-6]
	int startHour; //Целое число - час начала сушки
	int startMinut; //Целое число - минута начала сушки
	int duration_F; //Целое число - минуты
	int temp_F; //Целое число - температура
	int duration_S; //Целое число - минуты
	int temp_S; //Целое число - температура
};

//внешние функции
int AddDryEvent(int day, int hour, int minut, int duration_F, int temp_F, int duration_S, int temp_S);
int DelDryEvent(int day, int id);
int IsNeedExecuteEventID(int day, int hour, int minut);




//функции-свойства
int GetDurationEvent_F(int day, int id);
int GetTempEvent_F(int day, int id);
int GetDurationEvent_S(int day, int id);
int GetTempEvent_S(int day, int id);

//внутренние вспомогательные процедуры
int IsMayAdded(int day, int hour, int minut, int duration_F, int duration_S);
int ExecuteChecker(struct dryEvent* dayArray, int dayID, int day, int hour, int minut);
void SetUpEvent(struct dryEvent* dayArray, int id, int day, int hour, int minut, int duration_F, int temp_F, int duration_S, int temp_S);
void SetDownEvent(struct dryEvent* dayArray, int dayID, int id);
int GetMax(int a, int b);
int AbsoluteDayHourMinute(int day, int hour, int minute);
int AbsoluteTime(int time);
int ProcesCycle(struct dryEvent* dayArray, int dayID, int timeStart, int timeEnd);
struct dryEvent* GetPointerArray(int day);





#ifdef __cplusplus
}
#endif
#endif /* INC_DRYEVENT_H_ */
