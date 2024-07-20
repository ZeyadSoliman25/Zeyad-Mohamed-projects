/*
 * q18.c
 *
 *  Created on: Jul 27, 2023
 *      Author: zayedsoliman
 */


#include <stdio.h>
#include <math.h>


char power_of_square_number(int num);


int main(){
	int num = 0;
	char can_be_written = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	can_be_written = power_of_square_number(num);
	printf("%d", can_be_written);
}


char power_of_square_number(int num){
	char can_be_written = 0;
	for (int i = 2; i<= num; i++){
		for (int j = 2; j<= num; j++){
			if (log(num) == (j*log(i))){
				can_be_written = 1;
			}
		}
	}
	return can_be_written;
}
