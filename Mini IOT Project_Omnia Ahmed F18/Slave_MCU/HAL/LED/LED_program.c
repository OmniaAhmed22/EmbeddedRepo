/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "DIO_interface.h"

void HAL_LedPinInit()
{
 MCAL_DIO_voidSetPinDirection(LED_PORT , LED_PIN , DIO_OUTPUT);
	
}


void HAL_LedOn()
{
	MCAL_DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_HIGH);
	
}

void HAL_LedOff()
{
	MCAL_DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_LOW);
	
}


void HAL_LedToggle ()
{
	while(1)
	{
		MCAL_DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_HIGH);
		for(uint16_t i=0;i<=500;i++);
        MCAL_DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_LOW);
        for(uint16_t i=0;i<=500;i++);
	}
	
}

