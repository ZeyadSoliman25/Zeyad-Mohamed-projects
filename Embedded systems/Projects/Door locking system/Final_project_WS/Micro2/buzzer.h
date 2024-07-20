/*
 * buzzer.h
 *
 *  Created on: Oct 24, 2023
 *  Author: Zeyad Mohamed
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

#define BUZZER_PORT		PORTA_ID
#define BUZZER_PIN 		PIN0_ID

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);

#endif /* BUZZER_H_ */
