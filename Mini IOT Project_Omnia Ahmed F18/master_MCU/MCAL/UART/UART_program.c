/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_registers.h"
#include "UART_config.h"



void MCAL_UART_Init(void)
{
	/*Baud rate value variable*/
	uint16_t UBRR_Val ;


	/*Full configuration for UART*/
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
	/*Baud Rate Calculations*/
	UBRR_Val =  (((FRQ) / ((16 * BAUDRATE)) - 1));
	UBRRL = (uint8_t)UBRR_Val;
	/*Enable Transmitter and Receiver bits*/
	UCSRB = ((1 << RXEN) | (1 << TXEN));
}
void MCAL_UART_Transmit_byte(uint8_t data)
{
	while(!(UCSRA &(1<<UDRE)));
	UDR = data;
	//while (GET_BIT(UCSRA, TXC) != 1);
}



void MCAL_UART_send_string( uint8_t *ptr)
{
	uint16_t i=0;

	while(ptr[i] != '\0')
	{
		MCAL_UART_Transmit_byte(ptr[i]);
		i++;
	}
	MCAL_UART_Transmit_byte(ptr[i]);
}



uint8_t  MCAL_UART_recieve_byte(void)
{
	while (GET_BIT(UCSRA, RXC) != 1);
	return UDR ;


}



void  MCAL_UART_recieve_string(uint8_t * ptr)
{
	uint8_t i=0;
	ptr[i]=MCAL_UART_recieve_byte();
	while(ptr[i] !='#') // send this special character to inform  the receiver that it is the end of the string
	{
		i++;
		ptr[i]=MCAL_UART_recieve_byte();

	}
	ptr[i]='\0';


}

/* function to compare string received from HC05
  with a pre_defined string which is "on" word here
 */

uint8_t compareString(uint8_t arr1[10] , uint8_t arr2[10])
{
	uint16_t i=0;
	uint8_t flag=0;
	while((arr2[i]!='\0'))
	{
		if(arr1[i]==arr2[i])
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
		i++;
	}
	return flag ;
}
