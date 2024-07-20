/*
 * q13.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int floor_sum (float num1, float num2);


int main(){
	float num1 = 0;
	float num2 = 0;
	int sum = 0;
	printf("Enter two numbers: ");
	scanf("%f %f",&num1, &num2);
	sum = floor_sum(num1, num2);
	printf("Their floor sum is: %d", sum);
}

int floor_sum(float num1, float num2){
	return num1 + num2;
}
