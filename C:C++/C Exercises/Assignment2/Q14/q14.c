/*
 * q14.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>


void fibonacci_series (int num, int num2);


int main(){
	int num = 0;
	int num2 = 0;
	fibonacci_series(num, num2);
}

void fibonacci_series (int num,int num2){
	int sum = 0;
	if (num<1){
		for (int i = 0; i <=1; i++){
			printf("%d, ",i);
		}
		num = 1;
		num2 = 1;
		printf("%d, ", num);
	}
	sum = num + num2;
	num2 = num;
	num = sum;
	printf("%d, ",sum);
	fibonacci_series(num, num2);
}
