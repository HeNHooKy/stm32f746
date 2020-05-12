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

#define MAX_EVENTS 10 //максимум событий за день

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

#define EVENT_AWAY -1
#define EVENT_OK 1 //отчет

struct dryEvent
{
	uint8_t id; //порядковый номер события
	uint8_t startDay; //Целое число - день недели [0-6]
	uint8_t startHour; //Целое число - час начала сушки
	uint8_t startMinut; //Целое число - минута начала сушки
	uint8_t duration; //Целое число - минуты
	uint8_t temp; //Целое число - температура
};

//внешние функции
int AddDryEvent(uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration, uint8_t temp);
int DelDryEvent(uint8_t day, uint8_t id);
int IsNeedExecuteEventID(uint8_t day, uint8_t hour, uint8_t minut);

//внутренние вспомогательные процедуры
int IsMayAdded(struct dryEvent* dayArray, uint8_t max, uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration);
int ExecuteChecker(struct dryEvent* dayArray, uint8_t dayID, uint8_t day, uint8_t hour, uint8_t minut);
void SetUpEvent(struct dryEvent* dayArray, uint8_t id, uint8_t day, uint8_t hour, uint8_t minut, uint8_t duration, uint8_t temp);
void SetDownEvent(struct dryEvent* dayArray, uint8_t dayID, uint8_t id);

//функции-свойства
uint8_t GetDurationEvent(uint8_t day, uint8_t id);
uint8_t GetTempEvent(uint8_t day, uint8_t id);

#ifdef __cplusplus
}
#endif
#endif /* INC_DRYEVENT_H_ */
