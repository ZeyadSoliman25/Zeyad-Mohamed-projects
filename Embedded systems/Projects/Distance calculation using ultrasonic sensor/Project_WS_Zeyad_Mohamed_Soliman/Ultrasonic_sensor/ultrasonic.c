#include "ultrasonic.h"
#include "icu.h"
#include "std_types.h"
#include "gpio.h"
#include <util/delay.h>
#include <avr/io.h>

static	uint8 g_edgeCount = 0;
static	uint16 g_timePeriodHigh = 0;


void Ultrasonic_init(void){
	ICU_ConfigType configurations = {F_CPU_8, RAISING};
	ICU_init(&configurations);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
	_delay_ms(15);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	uint16 distance = 0; /* to not allow the value in distance variable be popped from the stack */
	Ultrasonic_Trigger();

	distance = (g_timePeriodHigh / 58.8);

	return distance;
}


void Ultrasonic_edgeProcessing(void){
	g_edgeCount++;

	if(g_edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_timePeriodHigh = ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount = 0;
	}

}
