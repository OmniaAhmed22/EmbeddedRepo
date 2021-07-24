
/*****************************************************************************/
 /* Author: Omnia Ahmed                                                       */
 /* Date  : 16/2/2021                                                         */
 /* Version: V01                                                              */ 
 /*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_interface.h"
#include "EXTI0_interface.h"
#include "LED_MATRIX_INTERFACE.h"
#include "EXTI0_interface.h"


extern u8 u8Data;

u8 arr1[]={0, 0, 60, 66, 66, 66, 0, 0,0, 124, 18, 18, 18, 124, 0, 0,0, 0, 2, 2, 126, 2, 2, 0};         /* array for "CAT" word on 8*8 LED matrix*/
u8 arr2[]={0, 0, 126, 66, 66, 60, 0, 0, 0 , 60, 66, 66, 66, 66, 60, 0 , 0, 60, 66, 66, 82, 82, 48, 0}; /* array for "DOG" word on 8*8 LED matrix*/

void voidPlay(void)
{


	switch (u8Data)
	{
	
		
		case 12:   /*when you press putton 1 in the IR controller, received data u8Data =12*/
		{
              VidLedMtrxAnimation ( arr1, 3);	 /* display " CAT" word*/
		      break;
		}
		case 24:  /*when you press putton 2 in the IR controller, received data u8Data =24*/
			{   VidLedMtrxAnimation ( arr2, 3); /* display " DOG" word*/
		        break;
			}
		

	}

}



int main()
{

	 RCC_voidInitSysClock();             /*Enable clock for RCC peripheral*/
	 RCC_voidEnableClock(RCC_APB2 , 0);  /*Enable clock for EXTI0         */
	 RCC_voidEnableClock(RCC_APB2 , 2);  /*Enable clock for GPIOA         */
	 RCC_voidEnableClock(RCC_APB2 , 3);  /*Enable clock for GPIOB         */

	 VidIR_init();                       /*Initialize the IR controller   */
	 HLEDMAT_voidInit();                 /*Initialize the LED matrix      */

	 VidIR_Start_Receive();              /*start receiving data from IR controller in Asynchronus fashion to decide displaying "CAT" or "DOG" */
	 
	 
while (1) 

{

	
}


}
