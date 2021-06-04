/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Common.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_Cfg.h"
#include <string.h>



static void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command);
static void HAL_LCD_voidWriteData(uint8_t Copy_u8Data);


void HAL_LCD_voidWriteCommand(uint8_t Copy_u8Command)
{
#if(LCD_BIT_MODE == MODE_8_BIT)

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_LOW); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	MCAL_DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Command);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	for( uint16_t r=0; r<10000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */
#elif(LCD_BIT_MODE == MODE_4_BIT)

	//MCAL_DIO_voidSetPinDirection(2,0,1);
	//	MCAL_DIO_voidSetPinValue(2 , 0 , 1);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_LOW); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Command & 0xF0) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	for( uint16_t r=0; r<10000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	for( uint16_t r=0; r<10000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_LOW); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Command << 4) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	for( uint16_t r=0; r<10000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	for( uint16_t r=0; r<1000;r++);

#endif

}

void HAL_LCD_voidWriteData(uint8_t Copy_u8Data)
{
#if(LCD_BIT_MODE == MODE_8_BIT)
	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*1 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	MCAL_DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Data);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	for( uint16_t r=0; r<1000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

#elif(LCD_BIT_MODE == MODE_4_BIT)

	MCAL_DIO_voidSetPinDirection(2,0,1);
	MCAL_DIO_voidSetPinValue(2 , 0 , 1);
	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*1 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Data & 0xF0) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	for( uint16_t r=0; r<10000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	for( uint16_t r=0; r<10000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	MCAL_DIO_voidSetPinValue(LCD_RS_PIN , DIO_HIGH); /*0 write Command */

	MCAL_DIO_voidSetPinValue(LCD_RW_PIN , DIO_LOW); /*0 write */

	LCD_DATA_PORT_REG = (Copy_u8Data << 4) | (LCD_DATA_PORT_REG & 0x0F) ;

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_HIGH); /*Enable is high */

	for( uint16_t r=0; r<1000;r++);

	MCAL_DIO_voidSetPinValue(LCD_E_PIN , DIO_LOW); /*Enable is low */

	for( uint16_t r=0; r<1000;r++);
#endif

}


void HAL_LCD_Init(void)
{
#if(LCD_BIT_MODE == MODE_8_BIT)
	MCAL_DIO_voidSetPinDirection(LCD_E_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RS_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RW_PIN , DIO_OUTPUT);

	MCAL_DIO_voidSetPortDirection(LCD_DATA_PORT , DIO_PORT_OUTPUT);

	for( uint16_t r=0; r<1000;r++);

	HAL_LCD_voidWriteCommand(0b00111100);

	for( uint16_t r=0; r<1000;r++);

	HAL_LCD_voidWriteCommand(0b00001111);

	for( uint16_t r=0; r<1000;r++);
	HAL_LCD_voidWriteCommand(0b00000001);

	for( uint16_t r=0; r<1000;r++);

#elif(LCD_BIT_MODE == MODE_4_BIT)

	MCAL_DIO_voidSetPinDirection(LCD_E_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RS_PIN , DIO_OUTPUT);
	MCAL_DIO_voidSetPinDirection(LCD_RW_PIN , DIO_OUTPUT);

	LCD_DATA_DIR_REG = (LCD_DATA_DIR_REG & 0x0F) | 0xF0 ;

	for( uint16_t r=0; r<10000;r++);

	//HAL_LCD_voidWriteCommand(0x33);

	//_delay_ms(2);

	//HAL_LCD_voidWriteCommand(0x32);

	//_delay_ms(2);

	HAL_LCD_voidWriteCommand(0b00101000);// 0x28

	for( uint16_t r=0; r<1000;r++);

	HAL_LCD_voidWriteCommand(0b00001111);

	for( uint16_t r=0; r<1000;r++);
	HAL_LCD_voidWriteCommand(0b00000001);

	for( uint16_t r=0; r<1000;r++);




#endif

}

void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character)
{
	HAL_LCD_voidWriteData(Copy_u8Character);
}

void HAL_LCD_voidWriteString(uint8_t arr[])
{
	uint8_t Loop = 0 ;

	while(arr[Loop] != NULL_CHAR)
	{
		HAL_LCD_voidWriteData(arr[Loop]);
		Loop++ ;
	}
}

void HAL_LCD_voidMoveCursor(uint8_t Copy_u8Row , uint8_t Copy_u8Col)
{
	/*if(Copy_u8Row == 0)
	{
		HAL_LCD_voidWriteCommand( 128 + Copy_u8Col);
	}
	else if(Copy_u8Row == 1)
	{
		HAL_LCD_voidWriteCommand( 128 + 0x40 + Copy_u8Col); //128 = 0x80 = 0b10000000
	}*/

	HAL_LCD_voidWriteCommand( 128 + (0x40 * Copy_u8Row) + Copy_u8Col);
}
void HAL_LCD_SpecialChar(uint8_t arr[] , uint8_t Copy_NoOfBlocks ,  uint8_t Copy_Row , uint8_t Copy_Col)
{
	uint8_t Loop ;

	HAL_LCD_voidWriteCommand(0x40);

	for(Loop = 0 ; Loop < Copy_NoOfBlocks * 8 ; Loop++)
	{
		HAL_LCD_voidWriteData(arr[Loop]);
	}

	HAL_LCD_voidMoveCursor(Copy_Row , Copy_Col);
}


void HAL_LCD_voidWriteNumbers(uint16_t Copy_u16Number)
{
	uint8_t  buffer[16];
	   itoa(Copy_u16Number,buffer,10);
	   HAL_LCD_voidWriteString(buffer);
}

void HAL_LCD_voidClearLCD()
{
HAL_LCD_voidWriteCommand(0b00000001);
}

