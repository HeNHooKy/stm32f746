/*
 * Parser.c
 *
 *  Created on: 11 мая 2020 г.
 *      Author: Митя
 */


#include "main.h"
#include "Parser.h"

//Готовые сообщения
uint8_t M1[10] = { 0x02, 0x45, 0x37, 0x30, 0x31, 0x30, 0x30, 0x03, 0x34, 0x30 };

//массивы для подготовки сообщений
uint8_t D_Pattern_2[SIZE_D2] = { 0x00, 0x00, 0x31, 0x30, 0x34, 0x00, 0x00, 0x00, 0x30, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t D_Address[3] = { 0x00, 0x00, 0x00 };
uint8_t D_Constant_2[4] = { 0x00, 0x00, 0x00, 0x00 };
uint8_t D_Constant_4[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

//готовое для отправки сообщение
uint8_t D_Message_2[SIZE_D2] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


//преобразование константы в массив из size/4 элементов с
//использованием логики больших и малых блоков
void GX_PARSE_Constant(uint8_t* constArray, unsigned int constant, int size)
{
	//Применим закон: address(n) = ((k)/(16)^n%16 = this) > 9 ? this ? this + 6;

	size = size / 4; //получаем количество блоков

	uint8_t small = 0x30; //объявляем и инициализируем большой и малый блок
	uint8_t big = 0x30;


	int i = 0;

	while (i < size - 1)
	{
		uint8_t nVal = constant % 16;
		nVal = nVal > 0x09 ? nVal + 0x07 : nVal; //вычисление значения блока
		small = small + nVal; //запись значения в блок

		nVal = (constant / 16) % 16;
		nVal = nVal > 0x09 ? nVal + 0x07 : nVal;// сдвиг ASCII
		big = big + nVal;

		constArray[i + 1] = small; //запись блоков в массив
		constArray[i] = big;

		constant = constant / 16 / 16; //уменьшаем константу по закону
		i = i + 2;

		small = 0x30;
		big = 0x30;
	}
}

//Преобразование адреса в массив из 3 элементов по 4 бита
void GX_PARSE_Address(uint8_t* addressArray, unsigned int address)
{
	unsigned int size = 3;

	address = address * 2; //проблема адресного пространства

	int i = size - 1;

	while (i >= 0)
	{
		uint8_t nVal = address % 16;
		nVal = nVal > 0x09 ? nVal + 0x07 : nVal; //вычисление значения блока + сдвиг ASCII

		addressArray[i] = 0x30 + nVal;

		address = address / 16; //уменьшаем константу по закону
		i = i - 1;
	}
}

//Метод подсчета контрольной суммы.
//принимает массив готового сообщения, в котором свободно две последние ячейки под контрольную сумму
void GX_SET_ControlSum(uint8_t* message, int size)
{
	int i = 1; //пропускаем первый элемент, т.к. там хранится начало сообщения

	uint16_t controlSum = 0x00;

	for (; i < size - 2; i++)
	{
		controlSum = controlSum + message[i];
	}

	uint8_t big = controlSum & 0x000F;
	uint8_t small = (controlSum >> 4) & 0x000F;

	big = big > 9 ? big + 0x07 : big;
	small = small > 9 ? small + 0x07 : small; //сдвиг ASCII

	message[size - 1] = big + 0x30;
	message[size - 2] = small + 0x30;
}

//Принимает шаблон сообщения, адрес в int формате и константу с её форматом
//подготовливает сообщение к отправке, добавляя
//STX, Header, address, constant, controlSum
void GX_DECIMICAL_Parse(uint8_t* messageArray, uint8_t* messagePattern, unsigned int mSize, unsigned int address, unsigned int constant, int cSize)
{
	unsigned int isSetAddress = 0; //проверка установлен ли адрес
	unsigned int isSetConstant = 0; //проверка установлена ли коснтанта
	unsigned int isSetControlSum = 0; //проверка установлена ли контрольная сумма

	for (int i = 0; i < mSize; i++)
	{	//копируем паттерн в подготавливаемое сообщение
		messageArray[i] = messagePattern[i];
	}
	messageArray[0] = STX; //Вставляем код начала сообщения
	messageArray[1] = HEADER; //Вставляем заголовк сообщения (45)
	messageArray[mSize - 3] = ETX; //Вставляем конец сообщения

	//берем указатель на нужный массив (размер 2 или размер 4)
	uint8_t* D_Constant = cSize == 16 ? D_Constant_2 : (cSize == 32 ? D_Constant_4 : NULL);

	//заполняем адресные и константные массивы актуальной информацией
	GX_PARSE_Address(D_Address, address);
	GX_PARSE_Constant(D_Constant, constant, cSize);

	//заполняем все свободные ячейки массива
	int i = 0;
	while (i < mSize)
	{
		if (messageArray[i] == 0)
		{
			if (!isSetAddress)
			{
				for (int a = 0; a < 3; a++)
				{	//копируем данные из адресного массива
					messageArray[i] = D_Address[a];
					i = i + 1;
				}
				isSetAddress = 1;
				continue;
			}
			if (!isSetConstant)
			{
				for (int c = 0; c < cSize / 4; c++)
				{	//копируем данные из константного массива
					messageArray[i] = D_Constant[c];
					i = i + 1;
				}
				isSetConstant = 1;
				continue;
			}
			if (!isSetControlSum)
			{	//вставляем контрольную сумму
				GX_SET_ControlSum(messageArray, mSize);
				isSetControlSum = 1;
				continue;
			}
		}
		i = i + 1;
	}
	//сообщение готово!
}
