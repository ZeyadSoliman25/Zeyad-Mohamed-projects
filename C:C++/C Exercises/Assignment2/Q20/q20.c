/*
 * q20.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

char consecutive_ones(short num);


int main(){
	short num = 0;
	char count = 0;
	printf("Enter a number: ");
	scanf("%hd", &num);
	count = consecutive_ones(num);
	printf("Number of consecutive ones are: %d", count);
}


char consecutive_ones(short num){
	char count = 0;
	char max = 0;
	while (num != 0){
		if ((num & 1) == 1){
			count ++ ;
			max = count;
			num >>=1;
		}
		if (((num & 1) == 1) && count >=1){
			count ++;
			max = count;
			num >>=1;
		}
		else {
			count = 0;
			num >>=1;
		}
	}
	return max;
}
