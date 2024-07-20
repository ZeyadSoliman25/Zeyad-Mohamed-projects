/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRD &= ~(1<<3);
	DDRC |= (1<<5);
	PORTC &= ~(1<<5);
	while (1){
		if (!(PIND & (1<<3))){
			_delay_ms(50);
			if (!(PIND & (1<<3))){
				PORTC |= (1<<5);
			}
		}
		else {
			PORTC &= ~(1<<5);
		}
	}

}
