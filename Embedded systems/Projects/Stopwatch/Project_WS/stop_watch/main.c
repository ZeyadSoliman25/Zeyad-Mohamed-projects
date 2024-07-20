/*	Author: Zeyad Mohamed
 * 	Project: Stop watch
 * 	date created: 12/9/2023
 */

#include<avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


char segments_disp[6]= {0}; // array to hold time values to be displayed on the 6 displays 7seg (sec1,sec2,min1,min2,hr1,hr2)


void Timer1_ctc(void){
	TCCR1A = (1<<WGM12); // enabling CTC mode
	TCCR1B = (1<<CS12) | (1<<CS10) | (1<<WGM12);// using prescaler FCPU/1024
	TCNT1 = 0;
	OCR1A = 977;// taken into consideration the decimal fractions in the calculation of the required time
	TIMSK |= (1<<OCIE1A); // masking for compare A is enabled
	SREG |= (1<<7); // global interrupt enabled
}


void Int0_init(void){
	DDRD &= ~(1<<2);
	PORTD |= (1<<2);
	MCUCR |= (1<<ISC01);
	MCUCR &= ~(1<<ISC00);
	GICR |= (1<<INT0);
}


void INT1_init (void){
	DDRD &= ~(1<<3);
	MCUCR |= (1<<ISC11) | (1<<ISC10);
	GICR |= (1<<INT1);
}


void INT2_init (void){
	DDRB &= ~(1<<2);
	PORTB |= (1<<2);
	MCUCSR &= ~(1<<ISC2);
	GICR |= (1<<INT2);
}


int main(){
	DDRC = 0x0F;
	DDRA = 0x3F;
	PORTC = 0;
	PORTA = 0;
	Timer1_ctc();
	Int0_init();
	INT1_init();
	INT2_init();
	while (1){
		//looping through the time values and enabling and disabling the 7segs
		PORTA |= (1<<0);
		PORTC = segments_disp[0];
		_delay_ms(5);
		PORTA &= ~(1<<0);
		PORTA |= (1<<1);
		PORTC = segments_disp[1];
		_delay_ms(5);
		PORTA &= ~(1<<1);
		PORTA |= (1<<2);
		PORTC = segments_disp[2];
		_delay_ms(5);
		PORTA &= ~(1<<2);
		PORTA |= (1<<3);
		PORTC = segments_disp[3];
		_delay_ms(5);
		PORTA &= ~(1<<3);
		PORTA |= (1<<4);
		PORTC = segments_disp[4];
		_delay_ms(5);
		PORTA &= ~(1<<4);
		PORTA |= (1<<5);
		PORTC = segments_disp[5];
		_delay_ms(5);
		PORTA &= ~(1<<5);
	}
}

ISR (TIMER1_COMPA_vect){
	segments_disp[0]++;
	if (segments_disp[0] > 9){
		segments_disp[0] = 0;
		segments_disp[1] ++ ;
	}
	if (segments_disp[1] > 5){
		segments_disp[1] = 0;
		segments_disp[2] ++ ;
	}
	if (segments_disp[2] > 9){
		segments_disp[2] = 0;
		segments_disp[3] ++;
	}
	if (segments_disp[3] > 5){
		segments_disp[3] = 0;
		segments_disp[4] ++;
	}
	if (segments_disp[4] > 9){
		segments_disp[4] = 0;
		segments_disp[5] ++;
	}
	if (segments_disp[5] > 9){
		segments_disp[5] = 0;
	}

}


ISR(INT0_vect){
	segments_disp[0] = 0;
	segments_disp[1] = 0;
	segments_disp[2] = 0;
	segments_disp[3] = 0;
	segments_disp[4] = 0;
	segments_disp[5] = 0;
	TCNT1 = 0; // to the start the counting of the 1 sec again
	TCCR1B |= (1<<CS12) | (1<<CS10);
}


ISR (INT1_vect){
	TCCR1B &= (~(1<<CS12)) & (~(1<<CS11)) & (~(1<<CS10));
}


ISR (INT2_vect){
	TCCR1B |= (1<<CS12) | (1<<CS10);
}
