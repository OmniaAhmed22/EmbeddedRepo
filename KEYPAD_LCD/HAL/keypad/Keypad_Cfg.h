//*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

//#define KEYPAD_NO_OF_ROWS			    3
//#define KEYPAD_NO_OF_COLUMNS       	3

#define KEYPAD_ROW_PORT   DIO_PORTC
#define KEYPAD_ROW_START  DIO_PIN_0
#define KEYPAD_ROW_END 	  DIO_PIN_2


#define KEYPAD_COL_PORT   DIO_PORTC
#define KEYPAD_COL_START  DIO_PIN_3
#define KEYPAD_COL_END    DIO_PIN_5

uint8_t Key_Matrix[KEYPAD_ROW_END - KEYPAD_ROW_START + 1 ][KEYPAD_COL_END - KEYPAD_COL_START + 1 ] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};




#endif /* KEYPAD_CFG_H_ */
