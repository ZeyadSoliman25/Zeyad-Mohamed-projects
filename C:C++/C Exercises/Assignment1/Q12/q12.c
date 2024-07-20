/*
 * q12.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num = 0;
	int result = 1;
	int i = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 1; i<= num; i++){
		result *= i;
	}
	printf("The factorial of %d is: %d", num, result);
}
