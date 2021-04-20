/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/



#ifndef UART_REG_H_
#define UART_REG_H_

#define UBRRL     (*(volatile uint8_t*)(0x29))

#define UCSRA     (*(volatile uint8_t*)(0x2B))
#define UCSRB     (*(volatile uint8_t*)(0x2A))

#define UCSRC     (*(volatile uint8_t*)(0x40))  // bit7 in this reg must be 1 to use this reg
#define UBRRH     (*(volatile uint8_t*)(0x40))

#define UDR       (*(volatile uint8_t*)(0x2C))

#endif
