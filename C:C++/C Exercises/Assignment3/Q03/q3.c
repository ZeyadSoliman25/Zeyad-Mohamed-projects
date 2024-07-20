/*
 * q3.c
 *
 *  Created on: Aug 1, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#define SIZE 5

void arrange(int *numbers, int size);


int main(){
	int numbers[SIZE] = {};
	int i = 0;
	printf("Enter an array of integers: ");
	for (i = 0; i<SIZE; i++){
		scanf("%d",&numbers[i]);
	}
	arrange(numbers, SIZE);
}


void arrange(int *numbers, int size){
	int i = 0;
	int j = 0;
	for (i = 0; i<size-1;i++){
		for (j = 0; j<size-i-1;j++){
			int temp = 0;
			if (numbers[j]>numbers[j+1]){
				temp = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = temp;
			}

		}
	}
	printf("The ascending order of the array: ");
	for (i = 0; i<5; i++){
		printf("%d ", numbers[i]);
	}
}
