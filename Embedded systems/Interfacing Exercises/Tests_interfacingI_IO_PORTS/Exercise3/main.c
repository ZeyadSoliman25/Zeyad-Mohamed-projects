/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC |= (1<<0);
	DDRC |= (1<<1);
	DDRB &= ~ (1<<0);
	DDRB &= ~ (1<<1);
	PORTC |= (1<<0);
	PORTC |= (1<<1);
	while (1){
		if ((PINB & (1<<0)) && (PINB &(1<<1))){
			PORTC &= ~(1<<0);
			PORTC &= ~(1<<1);
		}
		else if (PINB & (1<<0)){
			PORTC &= ~(1<<0);
		}
		else if (PINB & (1<<1)){
			PORTC &= ~(1<<1);
		}
		else {
			PORTC |= (1<<0);
			PORTC |= (1<<1);
		}

	}
}
