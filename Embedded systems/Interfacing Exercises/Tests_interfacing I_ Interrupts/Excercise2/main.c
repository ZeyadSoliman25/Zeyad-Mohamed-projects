#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>


void INT1_init (void){
	DDRD &= ~(1<<3);
	MCUCR |= (1<<ISC11);
	MCUCR &= ~(1<<ISC10);
	GICR |= (1<<INT1);
	SREG |= (1<<7);
}

ISR(INT1_vect){
	char i = 0;
	for (i = 0; i<5; i++){
		PORTC |= (1<<0) | (1<<1) | (1<<2);
		_delay_ms(500);
		PORTC &= ~(1<<0) & ~(1<<1) & ~(1<<2);
		_delay_ms(500);
		GIFR |= (1<<INTF1);
	}
}


int main(){
	DDRC |= (1<<0);
	DDRC |= (1<<1);
	DDRC |= (1<<2);
	PORTC &= ~(1<<0);
	PORTC &= ~(1<<1);
	PORTC &= ~(1<<2);
	INT1_init();

	while (1){
		PORTC |= 1;
		_delay_ms(500);
		PORTC &=~ 1;
		PORTC |= (1<<1);
		_delay_ms(500);
		PORTC &= ~(1<<1);
		PORTC |= (1<<2);
		_delay_ms(500);
		PORTC &= ~(1<<2);
	}
}
