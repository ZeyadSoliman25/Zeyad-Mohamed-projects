/*
 * q6.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num1 = 0 ;
	int num2 = 0 ;
	printf("Enter two numbers to compare: ");
	scanf("%d %d", &num1, &num2);
	if (num1 == num2){
		printf("the numbers are equal.");
	}
	else if (num1 > num2) {
		printf("The first number is greater.");
	}
	else if (num1 < num2) {
		printf("the second number is greater.");
	}
}
