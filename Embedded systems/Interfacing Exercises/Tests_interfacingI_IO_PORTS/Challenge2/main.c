/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRA &= ~(0x18);
	DDRD |= (0xFF);
	PORTD &= ~(0xFF);
	while (1){
		if (PINA & (1<<3)){
			_delay_ms(30);
			if (PINA &(1<<3)){
				PORTD = (0x55);
				_delay_ms(500);
				PORTD &= ~(0xFF);
				_delay_ms(500);
			}
		}
		else if (PINA & (1<<4)){
			_delay_ms(30);
			if (PINA &(1<<4)){
				PORTD = (0xAA);
				_delay_ms(500);
				PORTD &= ~(0xFF);
				_delay_ms(500);
			}
		}
		else {
			PORTD &= ~(0xFF);
		}
	}
}
