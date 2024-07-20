/*
 * q12.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int heater_activation (int temp);

int main(){
	int temp = 0;
	int time = 0;
	printf("Please enter the temperature of water: ");
	scanf("%d",&temp);
	time = heater_activation(temp);
	printf("The heater activation time is: %d minutes", time);
}

int heater_activation (int temp){
	int time = 0;
	if (0<=temp && temp<=30){
		time = 7;
	}
	else if (30<temp && temp<=60){
		time = 5;
	}
	else if (60<temp && temp<=90){
		time = 3;
	}
	else if (temp>90 && temp<100){
		time = 1;
	}
	else {
		time = -1;
	}
	return time;
}
