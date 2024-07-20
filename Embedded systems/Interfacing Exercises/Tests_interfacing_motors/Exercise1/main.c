/*
 * main.c
 *
 *  Created on: Sep 9, 2023
 *      Author: Zeyad Mohamed
 */
#include<avr/io.h>
#include <util/delay.h>

int main(){
	DDRA &= ~(0x07);
	DDRC |= (1<<0)|(1<<1);
	PORTC &= (~(1<<PC0))&(~(1<<PC1));

	while (1){
		if (PINA &(1<<0)){
			_delay_ms(30);
			if(PINA &(1<<0)){
				PORTC |= (1<<PC1);
				PORTC &= ~(1<<PC0);
			}
		}
		else if (PINA &(1<<1)){
			_delay_ms(30);
			if(PINA &(1<<1)){
				PORTC |= (1<<PC0);
				PORTC &= ~(1<<PC1);
			}
		}
		else if(PINA&(1<<2)) {
			_delay_ms(30);
			if(PINA &(1<<2)){
				PORTC &= (~(1<<PC0))&(~(1<<PC1));
			}
		}
	}
}
