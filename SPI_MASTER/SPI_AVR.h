/*
 * SPI_AVR.h
 *
 * Created: 7/21/2016 1:10:39 PM
 *  Author: Ahmed
 */ 


#ifndef SPI_AVR_H_
#define SPI_AVR_H_

#include "STD_TYPES.h"

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_SendChar(uint8_t idata);
uint8_t SPI_GetChar(void);




#endif /* SPI_AVR_H_ */
