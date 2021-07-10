/*
 * main.c
 *
 * Created: 06/29/21 8:57:33 PM
 *  Author: LENOVO
 */ 

// SLAVE //

#include <avr/io.h>
#include <avr/delay.h>
#include "SPI_AVR.h"
#include "LCD_Headers.h"

int main(void)
{
	SPI_SlaveInit() ;
	lcd_init() ;

	DDRC |= (1<<2) ;
	DDRD |= (1<<3) ;
    while(1)
    {
        uint8_t recieved_data = SPI_GetChar() ;
        if(recieved_data==(1+48))

        {
             PORTC |= (1<<2) ;
             _delay_ms(1000) ;
             PORTC &= ~(1<<2) ;
         }

        else if(recieved_data==(2+48))
        {
             PORTD |= (1<<3) ;
             _delay_ms(1000) ;
             PORTD &= ~(1<<3) ;
          }

        else if(recieved_data==(3+48))
                {
                     PORTD |= (1<<3) ;
                     PORTC |= (1<<2) ;
                     _delay_ms(1000) ;
                     PORTC &= ~(1<<2) ;
                     PORTD &= ~(1<<3) ;
                  }

        lcd_print_char(recieved_data) ;

    }
}
