/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC |= 1;
	DDRC |= (1<<1);
	DDRC |= (1<<2);
	PORTC &= ~1;
	PORTC &= ~(1<<1);
	PORTC &= ~(1<<2);

	while (1){
		PORTC |= 1;
		_delay_ms(500);
		PORTC &=~ 1;
		PORTC |= (1<<1);
		_delay_ms(500);
		PORTC &= ~(1<<1);
		PORTC |= (1<<2);
		_delay_ms(500);
		PORTC &= ~(1<<2);
	}
}
