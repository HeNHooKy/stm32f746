/*
 * UartController.c
 *
 *  Created on: May 7, 2020
 *      Author: Митя
 */

#include "main.h"
#include "Parser.h"
#include "UartController.h"
#include "string.h"
#include "cmsis_os.h"


extern UART_HandleTypeDef huart6;
extern uint8_t D_Message_2[SIZE_D2];
extern uint8_t D_Pattern_2[SIZE_D2];

extern uint8_t M1[10];

uint8_t d[2] = {0x01, 0x02};


//отправляет указанное значение на указанный адрес с учетом размера значения
void UC_GX_SEND_Decimical_2(unsigned int value, unsigned int address, int size)
{
	GX_DECIMICAL_Parse(D_Message_2, D_Pattern_2, SIZE_D2, address, value, size);
	HAL_UART_Transmit_IT(&huart6, D_Message_2, SIZE_D2);
	osDelay(100);
	HAL_UART_Transmit_IT(&huart6, M1, 10);
	HAL_GPIO_TogglePin(GPIOI, GPIO_PIN_1);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

}






