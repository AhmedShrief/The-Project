/*
 * LCD_FUNC.c
 *
 *  Created on: May 18, 2021
 *      Author: LENOVO
 */

#include <avr/io.h>
#include <avr/delay.h>


#define rs 1
#define rw 2
#define en 3

extern void lcd_command(unsigned char cmd)
{
	PORTA = cmd & 0xF0 ;
	PORTB &= ~ (1<<rs) ;
	PORTB &= ~ (1<<rw) ;
	PORTB |= (1<<en) ;
	_delay_ms(1) ;
	PORTB &= ~ (1<<en) ;
	_delay_ms(100) ;

	PORTA = cmd<<4 ;
	PORTB |= (1<<en) ;
	_delay_ms(1) ;
	PORTB &= ~ (1<<en) ;
	_delay_ms(100) ;
}

extern void lcd_data(unsigned char data)
{
	PORTA = data & 0xF0 ;
	PORTB |= (1<<rs) ;
	PORTB &= ~ (1<<rw) ;
	PORTB |= (1<<en) ;
	_delay_ms(1) ;
	PORTB &= ~(1<<en) ;

	PORTA = data<<4 ;
	PORTB |= (1<<en) ;
	_delay_ms(1) ;
	PORTB &= ~ (1<<en) ;
	_delay_ms(100) ;
}

extern void lcd_init()
{
	DDRA = 0xFF ;
	DDRB = 0xFF ;
	PORTB &= ~ (1<<en) ;
	lcd_command(0x33) ;
	lcd_command(0x32) ;
	lcd_command(0x28) ;
	lcd_command(0x0E) ;
	lcd_command(0x01) ;
	_delay_ms(200) ;
	lcd_command(0x06) ;
}

extern void lcd_print_string(const unsigned char * str )
{
	unsigned char i = 0 ;
	while(str[i] != '\0')
	{
		lcd_data(str[i]) ;
		i++ ;
		_delay_ms(100) ;
	}

}

extern void lcd_print_char(unsigned char ch )
{

		lcd_data(ch) ;

		_delay_ms(100) ;


}
