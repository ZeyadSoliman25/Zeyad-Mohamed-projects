#include "lcd.h"
#include "ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>


int main(){
	uint16 distance_measured = 0;

	LCD_init();
	Ultrasonic_init();

	SREG |= (1<<7);

	while(1){
		LCD_moveCursor(0,0);
		distance_measured = Ultrasonic_readDistance();
		LCD_displayString("Distance= ");
		LCD_intgerToString(distance_measured);
		LCD_displayString("cm ");
	}
}
