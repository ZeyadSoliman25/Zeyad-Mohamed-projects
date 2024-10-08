#include "timer.h"
#include "common_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>


static volatile void (*g_callBackPtr)(void) = NULL_PTR;


ISR(TIMER1_COMPA_vect){
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}


ISR(TIMER1_OVF_vect){
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}
}


void Timer1_init(const Timer1_ConfigType * Config_Ptr){
	TCCR1A = (TCCR1A & 0x0C);
	TCCR1B = (TCCR1B & 0xE0) | ((Config_Ptr -> mode) <<3) | (Config_Ptr -> prescaler);

	TCNT1 = Config_Ptr -> initial_value;

	if (Config_Ptr ->mode == CTC){
		OCR1A = Config_Ptr -> compare_value;
		TIMSK |= (1<<OCIE1A);
	}
	else if (Config_Ptr -> mode == NORMAL){
		TIMSK |= (1<<TOIE1);
	}
}


void Timer1_deInit(void){
	TCCR1B &= 0xF8;
	TCNT1 = 0;
	OCR1A = 0;
	TIMSK &= ~(1<<OCIE1A);
	TIMSK &= ~(1<<TOIE1);
}


void Timer1_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
}

