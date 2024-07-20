/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Vehicle control system speed control source code
 * =========================================================
 */
#include <stdio.h>


void traffic_light (short *vehicle_speed){
	char light = 0;
	printf("\nEnter the required color:\n");
	scanf(" %c",&light);
	if (light == 'g'){
		*vehicle_speed = 100;
	}
	else if (light == 'o'){
		*vehicle_speed = 30;
	}
	else {
		*vehicle_speed = 0;
	}
}
