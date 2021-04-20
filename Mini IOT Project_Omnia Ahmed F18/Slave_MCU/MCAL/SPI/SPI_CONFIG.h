/*
* SPI_CONFIG.h
*
* Created: 2/19/2021 8:18:36 PM
*  Author: karim
*/


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


#include "AVR_DIO_REG.h"

#define MASTER 1
#define SLAVE  0

#define MOSI 5
#define MISO 6
#define CLK  7
#define SS   4
#define SPIF  7

#define SPI_PORT   DDRB

#define SPI_MODE  SLAVE

#endif /* SPI_CONFIG_H_ */
