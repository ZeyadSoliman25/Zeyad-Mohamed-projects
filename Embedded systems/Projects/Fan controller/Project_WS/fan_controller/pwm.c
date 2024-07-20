#include "pwm.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle){
	uint8 set_duty_cycle = 0;

	switch (duty_cycle){
	case 25:
		set_duty_cycle = 64;
		break;
	case 50:
		set_duty_cycle = 128;
		break;
	case 75:
		set_duty_cycle = 192;
		break;
	case 100:
		set_duty_cycle = 255;
		break;
	default:
		set_duty_cycle = 0;
		break;
	}

	TCNT0 = 0;
	OCR0  = set_duty_cycle;
	DDRB  |= (1<<PB3);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
