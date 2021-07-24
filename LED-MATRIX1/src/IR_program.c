#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "STK_interface.h"
#include "EXTI0_interface.h"
#include "IR_interface.h"
#include "IR_config.h"
#include "NVIC_interface.h"




volatile u8 u8StartFlag     = 0;
volatile u32 u32FrameData[50]  = {0};
volatile u8 u8EdgeCounter   = 0;
volatile u8 u8Data = 0;
void voidTakeAction(void)
{
	u8 i;
	u8Data = 0; /*final received data*/

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			if ( (u32FrameData[17+i] >= 10000) && (u32FrameData[17+i] <= 14000) )
			{i=0;}
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		u8StartFlag     = 0;
				u32FrameData[0]=0;
				u8EdgeCounter   = 0;
		voidPlay();


	}

	else
	{
		u8StartFlag     = 0;
						u32FrameData[0]=0;
						u8EdgeCounter   = 0;/* Invalid Frame */
	}



}

 void voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}
}





void VidIR_init(void)
{

     /* GPIOA Enable Clock */
    RCC_voidEnableClock(RCC_APB2,IR_Receiver_PORT_CLK ); 

	/* IO Pins Initialization */
	MGPIO_VidSetPinDirection(IR_Receiver_PORT,IR_Receiver_PIN,INPUT_FLOATING);
	MEXTI_voidSetCallBack(voidGetFrame);
	
	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */
	
	
}



void VidIR_Start_Receive(void)
{
	MEXTI_voidInit();  /* A0 EXTI0 Enabled / Falling Edge */
	
}









