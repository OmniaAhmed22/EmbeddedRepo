/*
 //*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/



#ifndef  TIMER0_PRIVATE_H
#define  TIMER0_PRIVATE_H

#define TCNT0 (*(volatile uint8_t*)(0x52))
#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TIFR  (*(volatile uint8_t*)(0x58))
#define TIMSK (*(volatile uint8_t*)(0x59))
#define OCR0  (*(volatile uint8_t*)(0x5C))

#endif
