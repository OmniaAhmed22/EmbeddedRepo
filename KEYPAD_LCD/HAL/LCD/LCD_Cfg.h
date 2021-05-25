//*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "AVR_DIO_REG.h"

#define LCD_DATA_PORT	        DIO_PORTA

#define LCD_DATA_DIR_REG        DDRA //register
#define LCD_DATA_PORT_REG       PORTA //register
#define LCD_RS_PIN  	        DIO_PORTB , DIO_PIN_1
#define LCD_RW_PIN  	        DIO_PORTB , DIO_PIN_2
#define LCD_E_PIN  	            DIO_PORTB , DIO_PIN_3




/*MODE_4_BIT
 * MODE_8_BIT*/
#define LCD_BIT_MODE  MODE_8_BIT

#endif /* LCD_CFG_H_ */
