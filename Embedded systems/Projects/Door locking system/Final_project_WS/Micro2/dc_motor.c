#include "dc_motor.h"
#include "common_macros.h"
#include "pwm.h"


void DcMotor_Init(void){
	GPIO_setupPinDirection(PORT_ID, IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_ID, IN2_PIN, PIN_OUTPUT);

	MOTOR_PORT = (MOTOR_PORT & 0xFC) | (MOTOR_PORT & off);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	MOTOR_PORT |= state;
	PWM_Timer0_Start(speed);
}
