/*
 * Q1.c
 *
 *  Created on: Jul 4, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num1 = 0 ;
	int num2 = 0 ;
	int result = 0 ;
	printf("Enter two numbers:\n");
	scanf ("%d %d", &num1, &num2);
	result = ((num1 + num2) * 3) - 10 ;
	printf("The result is %d", result);
}
