/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Vehicle control system engine temperature source code
 * =========================================================
 */

#include <stdio.h>
#include <string.h>

void engine_temperature(short*engine_temp,char *engine_temp_control){
	printf("Enter the engine temperature: \n");
	scanf(" %hi", &*engine_temp);
	if (*engine_temp <= 100 || *engine_temp >= 150){
		strcpy(engine_temp_control,"ON");
		*engine_temp = 125;
	}
	else {
		strcpy(engine_temp_control,"OFF");
	}
}
