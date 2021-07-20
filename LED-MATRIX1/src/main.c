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
volatile u8 Arr[24]={0};
u8 arr1[]={0, 0, 60, 66, 66, 66, 0, 0,0, 124, 18, 18, 18, 124, 0, 0,0, 0, 2, 2, 126, 2, 2, 0};
u8 arr2[]={0, 0, 126, 66, 66, 60, 0, 0, 0 , 60, 66, 66, 66, 66, 60, 0 , 0, 60, 66, 66, 82, 82, 48, 0};

void voidPlay(void)
{


	switch (u8Data)
	{
	u8 j;
		//case 69: VidLedMtrxAnimation ( arr1, 3); break;
		case 12:
		{

			VidLedMtrxAnimation ( arr1, 3);
			for(j=0;j<24;j++)
			{Arr[j]=arr1[j];}
		break;
		}
		case 24:
			{   VidLedMtrxAnimation ( arr2, 3);
		         for(j=0;j<24;j++)
				{Arr[j]=arr2[j];}
		        break;
			}
		//default : VidLedMtrxAnimation ( arr1, 3); break;

	}

}



int main()
{

	 RCC_voidInitSysClock();
	 RCC_voidEnableClock(RCC_APB2 , 0);
	 RCC_voidEnableClock(RCC_APB2 , 2);
	 RCC_voidEnableClock(RCC_APB2 , 3);

	 VidIR_init();
	 HLEDMAT_voidInit();

	 VidIR_Start_Receive();
while (1)

{

	VidLedMtrxAnimation ( Arr, 3);
}


}
