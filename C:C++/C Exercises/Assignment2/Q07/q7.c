/*
 * q7.c
 *
 *  Created on: Jul 26, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int mult_num(int num1,int num2);

int main(){
	int num1 = 0 ;
	int num2 = 0 ;
	int multiple = 0;
	printf("Enter two numbers: ");
	scanf("%d %d",&num1, &num2);
	multiple = mult_num(num1,num2);
	if (multiple == 1){
		printf("The first number is multiple of second.");
	}
	else {
		printf("The numbers arenot multiples.");
	}
}

int mult_num(num1,num2){
	int multiple = 0;
	if (num1%num2 ==0){
		multiple = 1;
	}
	return multiple;
}
