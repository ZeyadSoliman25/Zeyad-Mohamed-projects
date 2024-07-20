/*
 * q1.c
 *
 *  Created on: Jul 20, 2023
 *      Author: zayedsoliman
 */
#include <stdio.h>
#include <math.h>
int main(){
	int x = 0 ;
	int result = 0 ;
	printf("Please enter a number: ");
	scanf("%d", &x);
	result = pow(x,3);
	printf("The cube of that number is: %d", result);

}
