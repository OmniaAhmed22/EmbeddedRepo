
 //*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "AVR_DIO_REG.h"

#define LCD_DATA_PORT	        DIO_PORTC

#define LCD_DATA_DIR_REG        DDRA                  /*register for  4bit config*/
#define LCD_DATA_PORT_REG       PORTA                 /*register for 4bit config */
#define LCD_RS_PIN  	        DIO_PORTD , DIO_PIN_5 /*0 for command, 1 for Data*/
#define LCD_RW_PIN  	        DIO_PORTD , DIO_PIN_6 /*0 for Write, 1 for Read*/
#define LCD_E_PIN  	            DIO_PORTD , DIO_PIN_7 




/*MODE_4_BIT  ,  MODE_8_BIT */
#define LCD_BIT_MODE   MODE_8_BIT

#endif 
