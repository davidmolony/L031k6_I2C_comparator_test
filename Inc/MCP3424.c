/*
 * MCP3424.c
 *
 *  Created on: 11 May 2019
 *      Author: Lenovo
 */
#include "MCP3424.h"
#include <stdint.h>	//srm: this is a standard library that comes with compiler. use <>


void MCP3424(I2C_HandleTypeDef* pI2C,UART_HandleTypeDef* pUART){
	if(pI2C != NULL){
		pI2CHandle = pI2C;
	}
	if(pUART != NULL){
		pUARTHandle = pUART;
		}
	  //HAL_I2C_IsDeviceReady(&hi2c1,(MCP3424add<<1),1,10);

	  if(HAL_I2C_IsDeviceReady(pI2CHandle,(MCP3424add<<1),1,10)==HAL_OK){
	                  HAL_UART_Transmit(pUARTHandle,"MCP3424 Ready\r",14, 10);
	  }
	  /////Write the config register to set the resolution
	  HAL_I2C_Mem_Read(pI2CHandle,(MCP3424add<<1),configSet,1,ADCdatarec,5,10);

	  //HAL_I2C_Master_Transmit(&hi2c1,(MCP3424add<<1),configSet,1,10);
	  /////Read the data back
	  HAL_I2C_Master_Receive(pI2CHandle,(MCP3424add<<1),ADCdatarec,5,10);

	  switch(Resolution){
	  case 12:
		ADCval=0;
			  			ADCval=(ADCdatarec[1]<<0)|(ADCdatarec[0]<<8);
			  			ADCval = (0x0800&ADCval ? (int)(0x07FF&ADCval)-0x0800 : ADCval);
		 HAL_UART_Transmit(pUARTHandle, "Resolution 12 \r", strlen("Resolution 12 \r"),5);
			  			break;
	  case 14:
		  	  	  	  	ADCval=(ADCdatarec[1]<<0)|(ADCdatarec[0]<<8);
			  			ADCval = (0x2000&ADCval ? (int)(0x1FFF&ADCval)-0x2000 : ADCval);
		 HAL_UART_Transmit(pUARTHandle, "Resolution 14", strlen("Resolution 14"),5);
		 	 	 	 	 break;


	  case 16:
		  	  	  	  	ADCval=(ADCdatarec[1]<<0)|(ADCdatarec[0]<<8);
			  			ADCval = (0x8000&ADCval ? (int)(0x7FFF&ADCval)-0x8000 : ADCval);
		 HAL_UART_Transmit(pUARTHandle, "Resolution 16", strlen("Resolution 16"),5);
		 	 	 	 	 break;
	  case 18:
		  	  	  	  	ADCval=(ADCdatarec[2]<<0)|(ADCdatarec[1]<<8)|(ADCdatarec[0]<<16);
			  			ADCval = (0x20000&ADCval ? (int)(0x1FFFF&ADCval)-0x20000 : ADCval);
		 HAL_UART_Transmit(pUARTHandle, "Resolution 16", strlen("Resolution 16"),5);
		 	 	 	 	 break;

	  }
	  char msgOut[32];
	  sprintf(msgOut, "ADCval: %d \r", ADCval);
	  HAL_UART_Transmit(pUARTHandle, (uint8_t*)msgOut, strlen(msgOut),5);
}
