/*
 * q9.c
 *
 *  Created on: Aug 4, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

void fibonacci_series(int *num_ptr);


int main(){
	int number = 0;
	printf("Enter the term of fibonacci series: ");
	scanf("%d",&number);
	fibonacci_series(&number);
	printf("The term is: %d", number);
}


void fibonacci_series(int *num_ptr){
	int num = 1;
	int temp = 0;
	int i = 0;
	for (i = 1;i < *num_ptr; i++){
		int sum = 0;
		sum = num + temp;
		temp = num;
		num = sum;
	}
	*num_ptr = num;
}
