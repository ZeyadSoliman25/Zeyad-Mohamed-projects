/*
 * q16.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int number_ones(unsigned char num);


int main(){
	unsigned char num = 0;
	int count = 0;
	printf("Enter a number: ");
	scanf("%hhu",&num);
	count = number_ones(num);
	printf("The number of 1's in that integer = %d", count);
}

int number_ones(unsigned char num){
	int count_ones = 0;
	while (1){
		if (num == 0){
			break;
		}
		else {
			if ((num & 1) == 1){
				count_ones += 1;
				num >>=1 ;
			}
			else {
				num >>=1 ;
			}
		}
	}
	return count_ones;
}
