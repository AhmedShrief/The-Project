/*
 * main.c
 *
 * Created: 06/29/21 8:57:33 PM
 *  Author: LENOVO
 */ 

// MASTER //

#include <avr/io.h>
#include <avr/delay.h>
#include "SPI_AVR.h"
#include "LCD_Headers.h"
#include "UART.h"


int main(void)
{
	SPI_MasterInit() ;

	uart_init() ;
	
    while(1)
    {
    	uint8_t received_uart = uart_recieve() ;
    	SPI_SendChar(received_uart) ;
    	_delay_ms(500) ;

    }


}
