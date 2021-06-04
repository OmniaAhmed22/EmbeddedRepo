//*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX  (*(volatile uint8_t*)(0x27))
#define ADCSRA (*(volatile uint8_t*)(0x26))
#define ADCH   (*(volatile uint8_t*)(0x25))
#define ADCL   (*(volatile uint8_t*)(0x24))
#define SFIOR  (*(volatile uint8_t*)(0x50))

#endif
