/*
 * q17.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>
int main(){
	int num = 0;
	int count = 0 ;
	printf("Enter a number: ");
	scanf("%d", &num);
	count= (num==0)?1:log10(num)+1;
	printf("The number of digits in that integer is: %d",count);
}
