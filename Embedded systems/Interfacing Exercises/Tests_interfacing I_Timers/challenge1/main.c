/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Zeyad Mohamed
 */

#include<avr/io.h>

char num = 0;
char tick = 0;

void Timer0_ovf(void){
	TCCR0 = (1<<FOC0) | (1<<CS02);
	TCNT0 = 134;
	TIMSK |= (1<<TOIE0);
	SREG |= (1<<7);
}


int main(){
	char segments[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};
	DDRA = 0xFE;
	PORTA = segments[0];
	Timer0_ovf();
	while(1){
		PORTA = segments[num];
	}
}

ISR (TIMER0_OVF_vect){

}
