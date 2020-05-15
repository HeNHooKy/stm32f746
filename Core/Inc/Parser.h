/*
 * Parser.h
 *
 *  Created on: 11 мая 2020 г.
 *      Author: Митя
 */

#ifndef INC_PARSER_H_
#define INC_PARSER_H_
#ifdef __cplusplus
extern "C" {
#endif


///ЭМУЛЯТОР SAMKOON - ПОДСТАВНОЙ SAMKOON
///ДАННАЯ БИБЛИОТЕКА ИСПОЛЬЗУЕТСЯ ТОЛЬКО ДЛЯ СООБЩЕНИЙ UNSIGNED 16 БИТ
///Допускается для обмена с GX только сообщениями группы M и группы D
///Разрешенные команды: запрос на M, запрос на D 16 бит, установка значения на M, установка значения на D 16 бит.

#define SIZE_D2 17 //стандартный размер сообщения decimical 2 на установку
#define SIZE_M 10 //стандартный размер сообщения M на установку
#define SIZE_REQUEST 13 //стандартный размер сообщения на запрос
#define GX_RECEIVE_SIZE_2 6 //длина ответа GX при запросе 1 байта информации
#define GX_RECEIVE_SIZE_4 8 //длина ответа GX при запросе 2 байта информации
#define SIZE_ADDRESS 3 //стандартные размеры адреса
#define SIZE_CONSTANT 4 //стандартные размера константы

//стартовое значение MEM для 6 полубита запроса
#define MEM_START 0x38 //стартовое значение для MEM

//Константы сообщения
#define GX_NULL 0x30 //стартовое значение - отсутствие значене на языке melsec. ASCII - 0
#define STX 0x02 //начало сообщения
#define ETX 0x03 //конец сообщения
#define HEADER 0x45//заголовок сообщения
#define GX_SET 0x31 //специальная комманда установки значения по адресу
#define GX_D_SIZE 0x32 //стандартный размер D_2
#define RESPONSE_FIRST_SIZE 0x30 //первые 4 бит установки размера ответа GX
#define RESPONSE_SECOND_M_SIZE 0x31//требует уложить ответ GX в 1 байт \n(вторые 4 бит установки размера ответа GX)
#define RESPONSE_SECOND_D_SIZE 0x32//требует уложить ответ GX в 2 байт \n(вторые 4 бит установки размера ответа GX)
#define GX_REQUEST 0x30 //специальная команда установки запроса
#define SET_M 0x37 //специальная команда установки M
#define FOLD_M 0x38 //специальная команда сброса M
#define GX_D 0x34 //команда D

//константы ошибок
#define GX_ERR_CONTROL_SUM -1 //ошибка: контрольная сумма не сходится

//Парсинг

uint8_t* GX_DECIMICAL_Parse(unsigned int address, unsigned int constant);
uint8_t* GX_MEM_Parse(unsigned int address, uint8_t status);



uint8_t* GX_MEM_Request(unsigned int address);
uint8_t* GX_DECIMICAL_Request(unsigned int address);

int GX_MEM_Unparse(unsigned int address);
int GX_DECIMICAL_Unparse();

//Внутренние функции

uint8_t* GX_PARSE_Constant(unsigned int constant);
uint8_t* GX_PARSE_Address(unsigned int address);
uint8_t* GX_MEM_Addres(unsigned int address);
int GX_MEM_Check(uint8_t data, unsigned int address);

//работа с контрольными суммами

void GX_GET_ControlSum(uint8_t* message, int size, uint8_t* b, uint8_t* s);
void GX_SET_ControlSum(uint8_t* message, int size);
int GX_CHECK_ControlSum(uint8_t* message, int size);



#ifdef __cplusplus
}
#endif
#endif /* INC_PARSER_H_ */
