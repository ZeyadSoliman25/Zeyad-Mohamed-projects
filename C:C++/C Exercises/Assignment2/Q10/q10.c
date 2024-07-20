/*
 * q10.c
 *
 *  Created on: Jul 26, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int hole_num(int num);

int main(){
	int num = 0;
	int sum = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	sum = hole_num(num);
	printf("The number of holes in the given number = %d", sum);
}

int hole_num(num){
	int sum = 0;
	int digit = 0;
	while (num){
		digit = num%10;
		num /= 10;
		switch (digit){
		case 0:
			sum += 1;
			break;
		case 4:
			sum += 1;
			break;
		case 6:
			sum += 1;
			break;
		case 9:
			sum += 1;
			break;
		case 8:
			sum += 2;
			break;
		}

	}
	return sum;
}
