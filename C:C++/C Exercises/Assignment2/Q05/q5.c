/*
 * q5.c
 *
 *  Created on: Jul 20, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num = 0;
	short result = 0;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (num % 2 == 0 ){
		result = 0;
	}
	else {
		result = 1;
	}
	printf("%hi", result);
}
