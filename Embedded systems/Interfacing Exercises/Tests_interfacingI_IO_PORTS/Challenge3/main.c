/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <util/delay.h>

int main(){
	char segments[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};
	char num = 0;
	DDRA = 0xFE;
	PORTA = segments[0];
	DDRC |= (1<<6) ;
	PORTC |= (1<<6);
	DDRD &= 0xF3;

	while (1){
		if (!(PIND & (1<<2))){
			_delay_ms(30);
			if (!(PIND & (1<<2))){
				if (num < 9){
					num ++;
					PORTA = segments[num];
				}
			}
			while (!(PIND & (1<<2)));
		}
		else if (!(PIND & (1<<3))){
			_delay_ms(30);
			if (!(PIND & (1<<3))){
				if (num > 0){
					num -- ;
					PORTA = segments[num];
				}
			}
			while (!(PIND & (1<<3)));
		}
		else {
			PORTA = segments[num];
		}
	}
}
