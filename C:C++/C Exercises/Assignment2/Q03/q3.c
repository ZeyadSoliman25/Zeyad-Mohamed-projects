/*
 * q3.c
 *
 *  Created on: Jul 20, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int x = 0;
	printf("Enter a number: ");
	scanf("%d", &x);
	if (x<0) {
		printf("The number is negative.");
	}
	else {
		printf("The number is positive.");
	}
}
