/*
 * SPI.h
 *
 * Created: 2/19/2021 8:18:47 PM
 *  Author: karim
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_CONFIG.h"


void SPI_Init(void);
void SPI_Transmit( uint8_t data);
uint8_t SPI_Receive(void);



#endif /* SPI_H_ */
