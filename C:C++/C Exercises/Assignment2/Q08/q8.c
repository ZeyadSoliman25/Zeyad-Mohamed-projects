/*
 * q8.c
 *
 *  Created on: Jul 26, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

void prime(int num1,int num2);

int main(){
	int num1 = 0;
	int num2 = 0;
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	printf("The prime numbers between intervals: \n");
	prime(num1, num2);
}

void prime(num1, num2){
	for (int j=num1; j<= num2; j++){
		int counter = 0;
		for (int i=2; i<=j; i++){
			if (j%i == 0){
				counter ++;
			}
		}
		if (counter == 1){
			printf("%d \n",j);
		}

	}
}
