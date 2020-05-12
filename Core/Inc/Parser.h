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
	#define SIZE_D2 17 //стандартный размер сообщения decimical 2

		//Константы сообщения
	#define STX 0x02
	#define ETX 0x03
	#define HEADER 0x45


	void GX_DECIMICAL_Parse(uint8_t* messageArray, uint8_t* messagePattern, unsigned int mSize, unsigned int address, unsigned int constant, int cSize);
	void GX_PARSE_Address(uint8_t* addressArray, unsigned int address);
	void GX_PARSE_Constant(uint8_t* constArray, unsigned int constant, int size);
	void GX_SET_ControlSum(uint8_t* message, int size);


#ifdef __cplusplus
}
#endif
#endif /* INC_PARSER_H_ */
