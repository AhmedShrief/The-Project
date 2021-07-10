/*
 * LCD_Headers.h
 *
 *  Created on: May 18, 2021
 *      Author: LENOVO
 */

#ifndef LCD_HEADERS_H_
#define LCD_HEADERS_H_




void lcd_init() ;

void lcd_command(unsigned char cmd) ;

void lcd_data(unsigned char data) ;

void lcd_print_string(const char * str ) ;

void lcd_print_char(unsigned char ch ) ;





#endif /* LCD_HEADERS_H_ */
