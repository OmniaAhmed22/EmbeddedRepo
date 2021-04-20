/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_interface.h"
#include "LED_interface.h"
#include"UART_interface.h"
#include"SPI_interface.h"

int main()
{
	SPI_Init();
	            uint8_t arr[10];       // string received from HC05
	            uint8_t arr2[10]="on";

			 	 MCAL_UART_Init();
			 	 HAL_LedPinInit();


	 while(1)
	 {


	MCAL_UART_recieve_string(arr);



	 if(compareString(arr,arr2))
	 {

		 uint8_t data=1;

		 		 SPI_Transmit(data);

	 }
	 else
	 {
		 uint8_t data =0;

		 		 SPI_Transmit(data);
	 }

	 }
	 return 0;
}




