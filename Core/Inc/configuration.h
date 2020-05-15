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

#define GROUP_M 1 //группа адресов GX M
#define GROUP_D 2 //группа адресов GX D

#define ADDRESS_TEMP_LEFT 195 //адрес принимающий температуру в левом отсеке
#define ADDRESS_TEMP_RIGHT 90 //адрес принимающий температуру в правом отсеке

#define ADDRESS_TIME_LEFT_OUT 111 //адрес принимающий время в левом отсеке
#define ADDRESS_TIME_RIGHT_OUT 110 //адрес принимающий время в правом отсеке

#define ADDRESS_TIME_LEFT_IN 335//адрес таймера левой стороны
#define ADDRESS_TIME_RIGHT_IN 332//адрес таймера правой стороны

#define ADDRESS_MANUAL_MODE_RIGHT 100 //адрес состояния ручного режима работы в правом отсеке
#define ADDRESS_MANUAL_MODE_LEFT 150 //адрес состояния ручного режима работы в левом отсеке
#define ADDRESS_FAST_MODE_LEFT 240 //адрес состояния режима быстрой сушки в левом отсеке
#define ADDRESS_FAST_MODE_RIGHT 200 //адрес состояния режима быстрой сушки в правом отсеке
#define ADDRESS_STANDART_MODE_LEFT 340 //адрес состояния режима стандартной сушки в левом отсеке
#define ADDRESS_STANDART_MODE_RIGHT 300 //адрес состояния режима стандартной сушки в правом отсеке


//команды
#define UC_REQUEST 0 //команда запроса состояния по выделеному адресу
#define UC_SET 1 //команда установки состояния на выделенный адрес

#define SET_M 0x37 //специальная команда установки M
#define FOLD_M 0x38 //специальная команда сброса M


#ifdef __cplusplus
}
#endif
#endif /* INC_CONFIGURATION_H_ */
