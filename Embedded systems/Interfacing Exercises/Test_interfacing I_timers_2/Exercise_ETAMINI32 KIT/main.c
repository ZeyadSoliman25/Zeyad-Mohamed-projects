/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Zeyad Mohamed
 */

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char tick = 0;

void Timer0_compare(void){
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<CS00) | (1<<CS02);
	TCNT0 = 0;
	OCR0 = 250;
	TIMSK |= (1<<OCIE0);
	SREG |= (1<<7);
}


int main(){
	DDRC |= (1<<0);
	PORTC &= ~(1<<0);
	Timer0_compare();
	while(1){

	}
}

ISR (TIMER0_COMP_vect){
	tick++;
	if (tick == 32){
		PORTC ^= (1<<0);
		tick = 0;
	}
}
