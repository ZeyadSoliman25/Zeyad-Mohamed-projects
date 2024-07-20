/*
 * main.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>

int main(){
	DDRC &= ~(1<<0);
	DDRB |= (1<<0);
	PORTB &= ~(1<<0);

	while (1){
		if (PINC & (1<<0)){
			PORTB |= (1<<0);
		}
		else{
			PORTB &= ~(1<<0);
		}
	}
}
