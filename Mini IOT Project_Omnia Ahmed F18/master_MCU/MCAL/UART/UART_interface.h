/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/

#ifndef UART_H_
#define UART_H_

#define TXEN    3  
#define RXEN    4
#define URSEL   7
#define UCSZ1   2
#define UCSZ0   1
#define TXC     6
#define RXC     7
#define UDRE    5




void   MCAL_UART_Init    (void);
uint8_t  MCAL_UART_recieve_byte(void);
void MCAL_UART_send_string( uint8_t *ptr);
void MCAL_UART_Transmit_byte(uint8_t data);
void  MCAL_UART_recieve_string(uint8_t * ptr);
uint8_t compareString(uint8_t arr1[10] , uint8_t arr2[10]);

#endif
