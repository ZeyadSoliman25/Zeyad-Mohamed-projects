/*
 * q13.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num = 0;
	int count = 0,i ;
	printf("Enter a number: ");
	scanf("%d", &num);
	for (i = 1 ; i<= num; i++){
		if (num % i == 0){
			count ++;
		}
	}
	if (count <= 2){
		printf("The number is prime");
	}
	else {
		printf("The number is not prime");
	}
}
