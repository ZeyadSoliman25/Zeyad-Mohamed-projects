/*
 * q3.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	float temp_c = 0 ;
	float temp_f = 0;
	printf("Enter a degree celsius temperature: ");
	scanf("%f", &temp_c);
	temp_f = (temp_c * 9/5) + 32 ;
	printf ("Fahrenheit temperature is: %f", temp_f);

}
