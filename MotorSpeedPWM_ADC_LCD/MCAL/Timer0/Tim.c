
 //*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_CONFIG.h"

#include "TIMER0.h"
#include "TIMER0_Private.h"
#include "DIO_interface.h"


void TIMER0_FastPWM_Initialization(void)
{
	MCAL_DIO_voidSetPinDirection (DIO_PORTB  , DIO_PIN_3, DIO_OUTPUT);
	
	SET_BIT(TCCR0, WGM01);SET_BIT(TCCR0, WGM00);/*Choose Fast PWM*/
	SET_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);/*Non- Inverting Mode*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);CLR_BIT(TCCR0, CS00);
}
void TIMER0_FastPWM_Set_Duty(uint8_t Duty)
{

	#if PWM_MODE == NON_INVERTING
	if(Duty==0)
		{OCR0=0;}
	else
	{OCR0 = ((BITS * Duty) / 100) -1;}
	#elif PWM_MODE == INVERTING
	if(Duty==0)
			{OCR0=0;}
	OCR0 = (BITS - 1) - (((BITS * Duty) / 100) - 1);
	#endif
}
