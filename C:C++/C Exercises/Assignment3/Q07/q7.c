/*
 * q7.c
 *
 *  Created on: Aug 4, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int odd_numbers(int *nth_term);


int main(){
	int nth_term = 0;
	printf("Enter the term you want to get from odd numbers: ");
	scanf("%d",&nth_term);
	nth_term = odd_numbers(&nth_term);
	printf("The term is: %d",nth_term);
}

int odd_numbers(int *nth_term){
	int i = 0;
	for (i = 1;i < 2*(*nth_term);i+=2){
	}
	return i-2;
}
