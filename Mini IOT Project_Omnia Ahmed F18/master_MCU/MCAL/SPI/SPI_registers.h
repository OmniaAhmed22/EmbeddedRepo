/*****************************************************************************/
/* Author  : omnia Ahmed                                                     */
/* Date    : 16/12/2021                                                      */
/* Version : V01                                                             */ 
/*****************************************************************************/


#ifndef SPI_REG_H_
#define SPI_REG_H_



#define SPCR (*(volatile   uint8_t*)(0x2D))
#define SPSR (*(volatile  uint8_t*)(0x2E))
#define SPDR (*(volatile  uint8_t*)(0x2F))

#endif
