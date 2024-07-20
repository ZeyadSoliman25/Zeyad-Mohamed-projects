/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Vehicle control system AC control source code
 * =========================================================
 */

#include <stdio.h>
#include <string.h>

void room_temperature(short *room_temp,char *ac){
	printf("\nEnter the room temperature: \n");
	scanf(" %hi", &*room_temp);
	if (*room_temp <= 10 || *room_temp >= 30){
		strcpy(ac,"ON");
		*room_temp = 20;
	}
	else {
		strcpy(ac,"OFF");
	}
}
