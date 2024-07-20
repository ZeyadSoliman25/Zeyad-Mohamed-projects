/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Zeyad Mohamed
 */
#include<avr/io.h>
#include <avr/interrupt.h>

char num = 0;
char tick = 0;

void Timer0_ovf(void){
	TCCR0 = (1<<FOC0) | (1<<CS02);
	TCNT0 = 0;
	TIMSK |= (1<<TOIE0);
	SREG |= (1<<7);
}


int main(){
	char segments[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};
	DDRA = 0xFE;
	DDRC |= (1<<6);
	PORTA = segments[0];
	PORTC |= (1<<6);
	Timer0_ovf();
	while(1){
		PORTA = segments[num];
	}
}

ISR (TIMER0_OVF_vect){
	tick++;
	if (tick == 245){
		if (num < 9){
			num++;
		}
		else if (num == 9){
			num = 0;
		}
		tick = 0;
	}
}

