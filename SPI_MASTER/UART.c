/*
 * UART.c
 *
 *  Created on: Jul 3, 2021
 *      Author: LENOVO
 */


#include "UART.h"

#define baud 103

void uart_init(void)
{
	UBRRH = (baud>>8) ;
	UBRRL = baud ;

	UCSRB = (1<<RXEN) | (1<<TXEN) ;
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) | (1<<USBS) ;
}

void uart_transmit(uint8_t data)
{
	while(!(UCSRA & (1<<UDRE))) ;

	UDR = data ;
}

uint8_t uart_recieve(void)
{
	while(!(UCSRA & (1<<RXC))) ;

	return UDR ;
}
