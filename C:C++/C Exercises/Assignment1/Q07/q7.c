/*
 * q7.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	printf ("Enter 3 numbers: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 < num2 && num1 < num3){
		printf("The smallest number is: %d", num1);
	}
	else if (num2 < num1 && num2 < num3){
		printf("The smallest number is: %d", num2);
	}
	else if (num3 < num1 && num3 < num1){
		printf("The smallest number is: %d", num3);
	}
}
