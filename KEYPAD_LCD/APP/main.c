//*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Common.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "DIO_interface.h"



int main()
{
	HAL_Keypad_voidInit();
    HAL_LCD_Init();

    while(1)
    {
    	   uint8_t pressedNo=NULL_CHAR;
    	   uint8_t *ptr=&pressedNo;

        HAL_Keypad_voidGetPressedKey(ptr);
        if((*ptr=='1')|(*ptr=='2')|(*ptr=='3')|(*ptr=='4')|(*ptr=='5')|(*ptr=='6')|(*ptr=='7')|(*ptr=='8')|(*ptr=='9'))
        {
	    HAL_LCD_voidWriteCharacter(*ptr);
        }
		
		else
		{
			/*Do Nothing*/
		}
		
    }
}
