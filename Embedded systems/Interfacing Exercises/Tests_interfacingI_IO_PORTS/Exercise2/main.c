/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRC |= (1<<2);
	PORTC &=~(1<<2);
	while(1){
		PORTC |=(1<<2);
		_delay_ms(1000);
		PORTC &=~(1<<2);
		_delay_ms(1000);
	}
}
