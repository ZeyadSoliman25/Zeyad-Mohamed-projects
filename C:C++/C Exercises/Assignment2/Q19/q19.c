/*
 * q19.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>


char power_3 (int num);


int main(){
	int num = 0;
	char can_be_written = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	can_be_written = power_3(num);
	printf("%d\n",can_be_written);
}


char power_3(num){
	int digit = 0;
	char can_be_written = 0;
	digit = log(num)/log(3);
	if (num == pow(3,digit)){
		can_be_written = 1;
	}
	else {
		can_be_written = 0;
	}
	return can_be_written;
}
