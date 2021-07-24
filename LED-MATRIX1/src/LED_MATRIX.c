
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <STK_interface.h>
#include "GPIO_INTERFACE.h"
#include "DELAY_INTERFACE.h"

#include "LED_MATRIX_INTERFACE.h"
#include "LED_MATRIX_CONFIG.h"



void HLEDMAT_voidInit(void)
{
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_ROW_7,OUTPUT_SPEED_2MHZ_PP);


	MGPIO_VidSetPinDirection(HLEDMAT_COL_0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(HLEDMAT_COL_7,OUTPUT_SPEED_2MHZ_PP);
}





static void VidDisableAllCols()
{

	MGPIO_VidSetPinValue( HLEDMAT_COL_0, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_1, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_2, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_3, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_4, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_5, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_6, HIGH );
	MGPIO_VidSetPinValue( HLEDMAT_COL_7, HIGH );
}

static void VidSetRowValues(u8 Copy_u8Data)
{
	u8 u8_Local_var1=GET_BIT(Copy_u8Data , 0);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_0 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 1);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_1 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 2);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_2 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 3);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_3 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 4);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_4 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 5);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_5 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 6);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_6 , u8_Local_var1);

	u8_Local_var1=GET_BIT(Copy_u8Data , 7);
	MGPIO_VidSetPinValue( HLEDMAT_ROW_7 , u8_Local_var1);
}


void VidLedMtrxDisplay (u8* Copy_u8DataArray)
{



	/**COL0**/
	VidDisableAllCols();
	VidSetRowValues(Copy_u8DataArray[0]);
	MGPIO_VidSetPinValue( HLEDMAT_COL_0, LOW);
	 MSTK_voidSetBusyWait( 2500 );


	 /**COL1**/
	 VidDisableAllCols();
	 VidSetRowValues(Copy_u8DataArray[1]);
	 MGPIO_VidSetPinValue( HLEDMAT_COL_1, LOW);
	 MSTK_voidSetBusyWait( 2500 );

	  /**COL2**/
	  VidDisableAllCols();
	  VidSetRowValues(Copy_u8DataArray[2]);
	  MGPIO_VidSetPinValue( HLEDMAT_COL_2, LOW);
	  MSTK_voidSetBusyWait( 2500 );

	  VidDisableAllCols();
	  VidSetRowValues(Copy_u8DataArray[3]);
	  MGPIO_VidSetPinValue( HLEDMAT_COL_3, LOW);
	  MSTK_voidSetBusyWait( 2500 );

	  VidDisableAllCols();
	  VidSetRowValues(Copy_u8DataArray[4]);
	  MGPIO_VidSetPinValue( HLEDMAT_COL_4, LOW);
	  MSTK_voidSetBusyWait( 2500 );


	  VidDisableAllCols();
	  VidSetRowValues(Copy_u8DataArray[5]);
	  MGPIO_VidSetPinValue( HLEDMAT_COL_5, LOW);
	  MSTK_voidSetBusyWait( 2500 );


	  VidDisableAllCols();
	  VidSetRowValues(Copy_u8DataArray[6]);
	  MGPIO_VidSetPinValue( HLEDMAT_COL_6, LOW);
	  MSTK_voidSetBusyWait( 2500 );


	  VidDisableAllCols();
	  VidSetRowValues(Copy_u8DataArray[7]);
	  MGPIO_VidSetPinValue( HLEDMAT_COL_7, LOW);
	  MSTK_voidSetBusyWait( 2500 );


}


static void VidArrayShift (u8* Copy_u8Array, u32 Copy_u32Size)
{


	   u8 Local_Temp=Copy_u8Array[0];
	   u32 Local_couter2;
	   for (Local_couter2=0;Local_couter2 <Copy_u32Size-1;Local_couter2++)
	   {
		   Copy_u8Array[Local_couter2] = Copy_u8Array[Local_couter2+1];

	   }
	   Copy_u8Array[Copy_u32Size-1]=Local_Temp;







}



void VidLedMtrxAnimation (u8* Copy_u8Array , u8 Copy_u8NoCharacters)
{

	u32 Local_couter1;
	u32 Local_couter3;



			for (Local_couter1=0;Local_couter1<(Copy_u8NoCharacters*8);Local_couter1++)
		    {
				 for (Local_couter3=0;Local_couter3<10;Local_couter3++)
		         {

					 VidLedMtrxDisplay (Copy_u8Array);

		         }


				   VidArrayShift (Copy_u8Array, Copy_u8NoCharacters*8);

		        }




}



