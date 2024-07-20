/*
 * q1.c
 *
 *  Created on: Jul 30, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

#define SIZE 4

int summation(int numbers_size, int *numbers);


int main(){
	int numbers[SIZE]={};
	int i = 0;
	int sum = 0;
	printf("Enter four numbers: ");
	for (i=0; i<SIZE; i++){
		scanf("%d", &numbers[i]);
	}
	sum = summation(SIZE, numbers);
	printf("Sum of array = %d", sum);
}


int summation(int numbers_size, int *numbers){
	int i = 0;
	int result = 0;
	for (i = 0; i<numbers_size; i++){
		result += numbers[i];
	}
	return result;
}

