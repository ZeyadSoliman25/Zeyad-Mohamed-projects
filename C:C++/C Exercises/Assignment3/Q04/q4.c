/*
 * q4.c
 *
 *  Created on: Aug 4, 2023
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
	int max = 0;
	int numbers_arrange[SIZE] = {};
	int index = 0;
	int loop_continue = size;
	while (loop_continue > 0){
		for (i = 0; i<size; i++){
			if (numbers[i]>max){
				max = numbers[i];
				index = i;
			}
		}
		numbers_arrange[loop_continue-1] = max;
		max = 0;
		numbers[index] = 0;
		loop_continue --;
	}
	printf("The ascending order of the array: ");
	for (i = 0; i<5; i++){
		printf("%d ", numbers_arrange[i]);
	}
}
