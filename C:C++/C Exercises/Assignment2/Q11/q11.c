/*
 * q11.c
 *
 *  Created on: Jul 26, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>

void second_pow(long num);

int main(){
	long num = 0;
	printf("Enter a number: ");
	scanf("%ld", &num);
	second_pow(num);
}

void second_pow(long num){
	int digit = 0;
	digit = log2(num);
	if (pow(2,digit) == num){
		printf("1");
	}
	else {
		printf("0");
	}
}
