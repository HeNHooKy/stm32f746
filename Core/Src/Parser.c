/*
 * Parser.c
 *
 *  Created on: 11 мая 2020 г.
 *      Author: Митя
 */


#include "main.h"
#include "Parser.h"


//МАССИВ АДРЕСА
uint8_t ADDRESS[SIZE_ADDRESS];

//МАССИВ КОНСТАНТЫ
//*может использоваться для формирования адреса M.
uint8_t CONSTANT[SIZE_CONSTANT];

//массивы принимаемых значений
uint8_t Receive_2[6]; //Массив для приема сообщений на 3 байта
uint8_t Receive_4[8] = { 0x02, 0x38, 0x38, 0x31, 0x33, 0x03, 0x44, 0x37 }; //Массив для приема сообщений на 4 байта

//МАССИВЫ СООБЩЕНИЙ ГОТОВЫХ К ОТПРАВКЕ

//D сообщения
uint8_t D_Message[SIZE_D2];
uint8_t D_Request[SIZE_REQUEST];

//M сообщения
uint8_t M_Message[SIZE_M];
uint8_t M_Request[SIZE_REQUEST];

//преобразование константы в массив из size/4 элементов с
//использованием логики больших и малых блоков
uint8_t* GX_PARSE_Constant(unsigned int constant)
{
	//Применим закон: address(n) = ((k)/(16)^n%16 = this) > 9 ? this ? this + 6;

	int size =  4; //получаем количество блоков

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

		CONSTANT[i + 1] = small; //запись блоков в массив
		CONSTANT[i] = big;

		constant = constant / 16 / 16; //уменьшаем константу по закону
		i = i + 2;

		small = 0x30;
		big = 0x30;
	}
	return CONSTANT;
}

//Преобразование адреса в массив из 3 элементов по 4 бита ТОЛЬКО ДЛЯ D
uint8_t* GX_PARSE_Address(unsigned int address)
{
	unsigned int size = 3;

	address = address * 2; //проблема адресного пространства

	int i = size - 1;

	while (i >= 0)
	{
		uint8_t nVal = address % 16;
		nVal = nVal > 0x09 ? nVal + 0x07 : nVal; //вычисление значения блока + сдвиг ASCII

		ADDRESS[i] = 0x30 + nVal;

		address = address / 16; //уменьшаем константу по закону
		i = i - 1;
	}
	return ADDRESS;
}

//Метод подсчета контрольной суммы.
//принимает массив готового сообщения, в котором свободно две последние ячейки под контрольную сумму
void GX_SET_ControlSum(uint8_t* message, int size)
{
	uint8_t big = 0x00;
	uint8_t small = 0x00;
	GX_GET_ControlSum(message, size, &big, &small);

	message[size - 1] = big;
	message[size - 2] = small;
}

//Принимает адрес в int формате и константу с её форматом
//подготовливает сообщение к отправке, добавляя
//STX, Header, address, constant, controlSum
uint8_t* GX_DECIMICAL_Parse(unsigned int address, unsigned int constant)
{
	unsigned int isSetAddress = 0; //проверка установлен ли адрес
	unsigned int isSetConstant = 0; //проверка установлена ли коснтанта
	unsigned int isSetControlSum = 0; //проверка установлена ли контрольная сумма

	GX_PARSE_Address(address);
	GX_PARSE_Constant(constant);

	D_Message[0] = STX; //Вставляем код начала сообщения
	D_Message[1] = HEADER; //Вставляем заголовк сообщения (45)
	D_Message[2] = GX_SET;
	D_Message[3] = GX_NULL;
	D_Message[4] = GX_D;
	D_Message[5] = ADDRESS[0];
	D_Message[6] = ADDRESS[1];
	D_Message[7] = ADDRESS[2];
	D_Message[8] = GX_NULL;
	D_Message[9] = GX_D_SIZE;
	D_Message[10] = CONSTANT[0];
	D_Message[11] = CONSTANT[1];
	D_Message[12] = CONSTANT[2];
	D_Message[13] = CONSTANT[3];
	D_Message[14] = ETX; //Вставляем конец сообщения

	GX_SET_ControlSum(D_Message, SIZE_D2);

	//сообщение готово!
	return D_Message;
}

//собирает сообщение для установки MEM на GX
uint8_t* GX_MEM_Parse(unsigned int address, uint8_t status)
{
	M_Message[0] = STX;
	M_Message[1] = HEADER;
	M_Message[2] = status;

	GX_PARSE_Constant(address);

	M_Message[3] = CONSTANT[0];
	M_Message[4] = CONSTANT[1];
	M_Message[5] = CONSTANT[2];
	M_Message[6] = CONSTANT[3];

	M_Message[7] = ETX;
	GX_SET_ControlSum(M_Message, SIZE_M);
	return M_Message;
}

//Проверка контрольной суммы
//Необходимо вызывать с передачей аргументов по ссылке
void GX_GET_ControlSum(uint8_t* message, int size, uint8_t *b, uint8_t *s)
{
	int i = 1; //пропускаем первый элемент, т.к. там хранится начало сообщения

	uint16_t controlSum = 0x00;

	for (; i < size - 2; i = i + 1)
	{
		controlSum = controlSum + message[i];
	}

	uint8_t big = controlSum & 0x000F;
	uint8_t small = (controlSum >> 4) & 0x000F;

	big = big > 9 ? big + 0x07 : big;
	small = small > 9 ? small + 0x07 : small; //сдвиг ASCII

	big = big + 0x30;
	small = small + 0x30;

	*b = big;
	*s = small;
}

//Разбирает сообщение извлекает из него состояние M по address
//Использует массив GX_Receive_2 - перед вызовом заполнить
//возвращает GX_ERR_CONTROL_SUM - контрольная сумма не сходится, необходим повторный запрос
//возвращает 1 : 0 - состояние М
int GX_MEM_Unparse(unsigned int address)
{
	uint8_t big = 0x01;
	uint8_t small = 0x01;

	GX_GET_ControlSum(Receive_2, 6, &big, &small);
	if (Receive_2[4] == small && Receive_2[5] == big)
	{
		//используются старые переменные,
		//чтобы не выделять память под новые
		small = Receive_2[1] - 0x30;
		big = Receive_2[2] - 0x30;

		small = small > 0x09 ? small - 0x07 : small;
		big = big > 0x09 ? big - 0x07 : big;

		uint8_t data = (small << 4) | (big);

		return GX_MEM_Check(data, address);
	}
	else
	{
		return GX_ERR_CONTROL_SUM;
	}
}

//Проверка состояния M по address
int GX_MEM_Check(uint8_t data, unsigned int address)
{
	unsigned int n = address % 8;
	return ((data & (1 << n)) > 0);
}

//формирует адрес для M_REQUEST
//внутренняя функция
uint8_t* GX_MEM_Addres(unsigned int address)
{
	address = address / 8;
	int i = 2;
	for (; i >= 1; i = i - 1)
	{
		uint8_t nVal = address % 16;
		nVal = nVal > 0x09 ? nVal + 0x07 : nVal; //вычисление значения блока + сдвиг ASCII

		ADDRESS[i] = 0x30 + nVal;

		address = address / 16; //уменьшаем константу по закону
	}
	uint8_t nVal = address % 16 + MEM_START;//ВАЖНО: изменена калибровка, т.к.
	nVal = nVal > 0x39 ? nVal + 0x07 : nVal;//стартовое значение разряда 38

	ADDRESS[0] = nVal;
	return ADDRESS;
}

//Собирает запрос для проверки состояния M по address
//использует массивы: M_REQUEST_Message, M_REQUEST_Address
uint8_t* GX_MEM_Request(unsigned int address)
{
	M_Request[0] = STX;
	M_Request[1] = HEADER;
	M_Request[2] = GX_REQUEST;
	M_Request[3] = GX_REQUEST;
	M_Request[4] = MEM_START;

	GX_MEM_Addres(address);

	M_Request[5] = ADDRESS[0];
	M_Request[6] = ADDRESS[1];
	M_Request[7] = ADDRESS[2];

	M_Request[8] = RESPONSE_FIRST_SIZE;
	M_Request[9] = RESPONSE_SECOND_M_SIZE;
	M_Request[10] = ETX;

	GX_SET_ControlSum(M_Request, SIZE_REQUEST);
	return M_Request;
}


//Формирует запрос на получение состояния D по address
//Использует массивы D_Request[SIZE_REQUEST], ADDRESS[3]
//возвращает готовый к отправке массив данных
uint8_t* GX_DECIMICAL_Request(unsigned int address)
{
	GX_PARSE_Address(address);
	D_Request[0] = STX;
	D_Request[1] = HEADER;
	D_Request[2] = GX_REQUEST;
	D_Request[3] = GX_REQUEST;
	D_Request[4] = GX_D;
	D_Request[5] = ADDRESS[0];
	D_Request[6] = ADDRESS[1];
	D_Request[7] = ADDRESS[2];
	D_Request[8] = RESPONSE_FIRST_SIZE;
	D_Request[9] = RESPONSE_SECOND_D_SIZE;
	D_Request[10] = ETX;
	GX_SET_ControlSum(D_Request, SIZE_REQUEST);
	return D_Request;
}


//Разбирает принятое сообщение
//Используя массив Receive_4[8]
//возвращает состояние D
int GX_DECIMICAL_Unparse()
{
	uint8_t small = 0x01;
	uint8_t big = 0x01;

	GX_GET_ControlSum(Receive_4, 8, &big, &small);
	if (Receive_4[6] != small || Receive_4[7] != big)
	{	//контрольная сумма не сходится
		return GX_ERR_CONTROL_SUM;
	}

	//Считываем данные и приводим их к понятному виду
	uint8_t smaller = Receive_4[1] - GX_NULL; //от меньшего
	small = Receive_4[2] - GX_NULL;
	big = Receive_4[3] - GX_NULL;
	uint8_t bigger = Receive_4[4] - GX_NULL; //к большему

	smaller = smaller > 0x09 ? smaller - 0x07 : smaller;
	small = small > 0x09 ? small - 0x07 : small;
	big = big > 0x09 ? big - 0x07 : big;
	bigger = bigger > 0x09 ? bigger - 0x07 : bigger;

	small = (smaller << 4) | small;
	big = (big << 4) | bigger;

	uint16_t result = (big << 8) | small;
	return result;
}
