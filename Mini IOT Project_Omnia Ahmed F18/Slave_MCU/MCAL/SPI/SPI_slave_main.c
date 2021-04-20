/*
 * SPI_slave.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Administrator
 */

/*****************************************************************************/
/* Author  : Omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_interface.h"
#include "LED_interface.h"
#include"SPI_interface.h"

int main()
{
	SPI_Init();
	HAL_LedPinInit();





	 while(1)
	 {

		            uint8_t received_data;       // string received from HC05
		 	            received_data= SPI_Receive();
		 	            if( received_data==1)
		 	            {
		 	            	HAL_LedOn();
		 	            }

		 	            else
		 	            {
		 	            	HAL_LedOff();

		 	            }
        }

}

