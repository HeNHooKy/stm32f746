/*
 * configuration.h
 *
 *  Created on: 14 мая 2020 г.
 *      Author: Митя
 */

#ifndef INC_CONFIGURATION_H_
#define INC_CONFIGURATION_H_
#ifdef __cplusplus
extern "C" {
#endif

#define GROUP_M 1
#define GROUP_D 2

#define ADDRESS_TEMP_LEFT 114 //адрес принимающий температуру в левом отсеке
#define ADDRESS_TEMP_RIGHT 112 //адрес принимающий температуру в правом отсеке

#define ADDRESS_TIME_LEFT_OUT 111 //адрес принимающий время в левом отсеке
#define ADDRESS_TIME_RIGHT_OUT 110 //адрес принимающий время в правом отсеке

#define ADDRESS_TIME_LEFT_IN //адрес таймера левой стороны
#define ADDRESS_TIME_RIGHT_IN //адрес таймера правой стороны

#define ADDRESS_MANUAL_MODE_RIGHT 100 //адрес состояния ручного режима работы в правом отсеке
#define ADDRESS_MANUAL_MODE_LEFT 150 //адрес состояния ручного режима работы в левом отсеке
#define ADDRESS_FAST_MODE_LEFT 240 //адрес состояния режима быстрой сушки в левом отсеке
#define ADDRESS_FAST_MODE_RIGHT 200 //адрес состояния режима быстрой сушки в правом отсеке
#define ADDRESS_STANDART_MODE_LEFT 400 //адрес состояния режима стандартной сушки в левом отсеке
#define ADDRESS_STANDART_MODE_RIGHT 300 //адрес состояния режима стандартной сушки в правом отсеке



#ifdef __cplusplus
}
#endif
#endif /* INC_CONFIGURATION_H_ */
