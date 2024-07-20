/*
 * q6.c
 *
 *  Created on: Aug 4, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#define SIZE 7
int first_occurence(int *numbers, int size, int digit);


int main(){
	int numbers[SIZE]={1,1,2,3,3,4,4};
	int digit = 0;
	int index = 0;
	printf("Enter a number to search: ");
	scanf("%d",&digit);
	index = first_occurence(numbers,SIZE,digit);
	printf("First occurence of %d = %d",digit,index);
}


int first_occurence(int *numbers, int size, int digit){
	int i = 0;
	int index = 0;
	for (i = 0; i<size; i++){
		if (numbers[i]==digit){
			index = i;
		}
	}
	return index;
}

