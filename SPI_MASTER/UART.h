/*
 * UART.h
 *
 *  Created on: Jul 3, 2021
 *      Author: LENOVO
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

void uart_init(void) ;

void uart_transmit(uint8_t data) ;

uint8_t uart_recieve(void) ;



#endif /* UART_H_ */
