/*
 * timer.h
 *
 *  Created on: Oct 23, 2023
 *  Author: Zeyad Mohamed
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"

typedef enum {
	NO_CLOCK, FCPU_1, FCPU_8, FCPU_64, FCPU_256, FCPU_1024
}Timer1_Prescaler;


typedef enum {
	NORMAL, CTC
}Timer1_Mode;


typedef struct {
	uint16 initial_value;
	uint16 compare_value;
	Timer1_Prescaler prescaler;
	Timer1_Mode mode;
}Timer1_ConfigType;


void Timer1_init(const Timer1_ConfigType * Config_Ptr);

void Timer1_deInit(void);

void Timer1_setCallBack(void(*a_ptr)(void));


#endif /* TIMER_H_ */
