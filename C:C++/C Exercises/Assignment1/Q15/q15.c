/*
 * q15.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>
int main(){
	int num = 0;
	int power = 0;
	double result = 0;
	printf("Enter a number and its power: ");
	scanf("%d %d", &num, &power);
	result = pow(num, power);
	printf("The result = %.1lf", result);
}
