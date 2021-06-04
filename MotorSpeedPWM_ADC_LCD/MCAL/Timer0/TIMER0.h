/*
 //*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 14/4/2021                                                      */
/* Version : V01                                                             */
/*****************************************************************************/


#ifndef TIMER0_H_
#define TIMER0_H_



#define F_OSC     16
#define BITS      256
#define MISECOND  1000
#define PRESCALER 1024

#define NORMAL_MODE              0
#define PHASECORRECT_PWM_MODE    1
#define CTC_MODE                 2
#define FAST_PWM_MODE            3

#define INVERTING     0
#define NON_INVERTING 1

#define PRE_NOCLK    0
#define PRE_CLK8     1
#define PRE_CLK64    2
#define PRE_CLK256   3
#define PRE_CLK1024  4

#define WGM01  3
#define WGM00  6
#define COM01  5
#define COM00  4
#define CS02   2
#define CS01   1
#define CS00   0




/*Polling Mode*/

//void TIMER0_WITHOUT_INTERRUPT_Initialization(void);
//void TIMER0_WITHOUT_INTERRUPT_Set_Delay(uint32_t Delay, uint8_t ocr);

/*Interrupt Mode*/
//void TIMER0_WITH_INTERRUPT_Initialization(void);
//void TIMER0_WITH_INTERRUPT_Set_Delay(uint32_t Delay, uint8_t ocr);

void TIMER0_FastPWM_Initialization(void);
void TIMER0_FastPWM_Set_Duty(uint8_t Duty);

#endif /* TIMER0_H_ */
