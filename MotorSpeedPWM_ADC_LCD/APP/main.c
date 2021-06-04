
 /*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0.h"
#include "DIO_interface.h"

#include "ADC.h"
#include "LCD_interface.h"


int main()
{

  TIMER0_FastPWM_Initialization();
  ADC_Init   (ADC0);
  HAL_LCD_Init();
  uint8_t dutyCyle=0;
  uint16_t lastReading=0;
  while(1)
  {
	  uint16_t InputVoltage = (ADC_Read()*5)/1024;
	  uint16_t reading=ADC_Read();
	  uint8_t dutyCyle= ((InputVoltage*100)/5);
	  TIMER0_FastPWM_Set_Duty(dutyCyle);
	  if(reading!=lastReading)
	  {
		  HAL_LCD_voidClearLCD();
	     HAL_LCD_voidWriteNumbers( reading);

	  }
	  lastReading=reading;







  }
}
