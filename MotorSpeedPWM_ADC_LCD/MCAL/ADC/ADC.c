/*
 //*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"
#include "ADC_Private.h"

/*Functions implementations*/
void ADC_Init(uint8_t channel)/*Initialize ADC*/
{
	/*Choose voltage source - AVCC*/
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
	/*Choose RIGHT adjust*/
	CLR_BIT(ADMUX, ADLAR);
	/*Choose channel*/
	switch(channel)
	{
		case ADC0:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC1:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);
		break;
		case ADC2:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC3:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);CLR_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);
		break;
		case ADC4:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC5:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);CLR_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);
		break;
		case ADC6:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);CLR_BIT(ADMUX, MUX0);
		break;
		case ADC7:
		CLR_BIT(ADMUX, MUX4);CLR_BIT(ADMUX, MUX3);SET_BIT(ADMUX, MUX2);SET_BIT(ADMUX, MUX1);SET_BIT(ADMUX, MUX0);
		break;
	}
	
	/*Use auto trigger mode*/
	SET_BIT(ADCSRA, ADATE);
	/*Free running mode*/
	SFIOR&=(00011111);
	/*Choose Prescaler*/
	SET_BIT(ADCSRA, ADPS2);SET_BIT(ADCSRA, ADPS1);SET_BIT(ADCSRA, ADPS0);
	/*ADC Enable*/
	SET_BIT(ADCSRA, ADEN);
}
uint16_t ADC_Read(void)/*Read value of current ADC*/
{
	uint16_t var = 0;
	/*Start of conversion signal - SOC*/
	SET_BIT(ADCSRA, ADSC);
	/*Wait till flag is set automatically - EOC*/
	while (GET_BIT(ADCSRA, ADIF) != 1);/*Polling mode*/
	/*Return value*/
	var = ADCL;
	var |= (ADCH<<8);
	SET_BIT(ADCSRA, ADIF);
	return var;

}
