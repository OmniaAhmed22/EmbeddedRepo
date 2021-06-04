/*
 //*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/



#ifndef ADC_H_
#define ADC_H_

/*Define names for channel*/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4

#define ADATE  5
#define ADEN   7
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0
#define ADSC   6
#define ADIF   4





void     ADC_Init   (uint8_t channel);           /*Initialize ADC*/
uint16_t  ADC_Read   (void);                     /*Read value of current ADC*/


#endif 
