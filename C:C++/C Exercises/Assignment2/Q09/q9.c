/*
 * q9.c
 *
 *  Created on: Jul 26, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

void swap (int num1, int num2);

int main(){
	int num1 = 0;
	int num2 = 0;
	printf("Enter x & y: ");
	scanf("%d %d", &num1, &num2);
	printf("The two numbers before swapping x=%d, y=%d\n", num1,num2);
	swap(num1, num2);
}

void swap(int num1, int num2){
	int x = num2;
	int y = num1;
	printf("The two numbers after swapping x=%d, y=%d", x,y);
}

