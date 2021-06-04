/******************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define MODE_4_BIT 0
#define MODE_8_BIT 1


extern void HAL_LCD_Init(void);

extern void HAL_LCD_voidWriteCharacter(uint8_t Copy_u8Character);

extern void HAL_LCD_voidWriteString(uint8_t arr[]);

extern void HAL_LCD_voidMoveCursor(uint8_t Copy_u8Row , uint8_t Copy_u8Col);
void HAL_LCD_voidWriteNumbers(uint16_t Copy_u16Number);
void HAL_LCD_voidClearLCD();

void HAL_LCD_SpecialChar(uint8_t arr[] , uint8_t Copy_NoOfBlocks ,  uint8_t Copy_Row , uint8_t Copy_Col);

#endif /* LCD_INTERFACE_H_ */
