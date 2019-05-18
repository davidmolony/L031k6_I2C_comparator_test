/*
 * MCP3424.h
 *
 *  Created on: 11 May 2019
 *      Author: Lenovo
 */
//#include "MCP3424.c"	//WTF? why?

/*HERE goes explanation of what this library does.*/


#ifndef MCP3424_H_
#define MCP3424_H_
//since you are going to use HAL, you need to explicitly declare and use HAL header
#include "stm32l0xx_hal.h"

/* HERE goes declaration of all functions.
 * You should probably separate functions that initialise the hardware and functions
 * that then use the hardware. */
void MCP3424();

/* would be good to have explanation of what each variable does.*/
I2C_HandleTypeDef*	pI2CHandle;
UART_HandleTypeDef* pUARTHandle;

uint8_t ADCdatarec[5] = {0};
uint16_t MCP3424add = 0b0000000001101000;
uint32_t ADCval=0;
int Resolution =18;
uint8_t configSet = 0b10011100;

#endif /* MCP3424_H_ */
