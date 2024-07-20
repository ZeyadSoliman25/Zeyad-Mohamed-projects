/*
 * main.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	unsigned char flag = 0;
	DDRB &= ~(1<<0);
	DDRC |= (1<<0);
	PORTC |= (1<<0);
	PORTB |= (1<<0);
	while (1){
		if (!(PINB & (1<<0))){
			_delay_ms(30);
			if (!(PINB & (1<<0))){
				//while(!(PINB & (1<<0))); for simple applications
				if (flag == 0){ //better for any applications to do one time only
					PORTC ^= (1<<0);
					flag = 1;
				}
			}
		}
		else {
			flag = 0;
		}
	}
}
