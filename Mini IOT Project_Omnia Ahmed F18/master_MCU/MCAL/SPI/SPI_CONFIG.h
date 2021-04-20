/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 16/12/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/

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

#define SPI_MODE  MASTER

#endif 
