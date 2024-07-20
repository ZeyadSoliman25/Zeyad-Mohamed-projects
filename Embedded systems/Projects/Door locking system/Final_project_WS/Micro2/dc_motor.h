#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
#include <avr/io.h>
#include "gpio.h"

#define MOTOR_PORT		PORTB
#define PORT_ID 		PORTB_ID
#define IN1_PIN   		PIN0_ID
#define IN2_PIN 		PIN1_ID

typedef enum{
	off,clockwise,anticlockwise
}DcMotor_State;

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
