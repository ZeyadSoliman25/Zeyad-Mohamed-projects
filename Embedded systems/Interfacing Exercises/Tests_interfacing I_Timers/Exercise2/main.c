/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Zeyad Mohamed
 */
#include <avr/io.h>

void Timer0_ovf_Init(void){
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);

}

