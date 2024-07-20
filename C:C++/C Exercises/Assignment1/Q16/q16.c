/*
 * q16.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>
int main(){
	int num = 0;
	int count = 0;
	int rev_num = 0, i;
	printf("Enter a number: ");
	scanf("%d", &num);
	count=(num==0)?1:log10(num)+1;
	for (i = count; i>= 1; i--){
		rev_num = num%10*pow(10,i-1) + rev_num;
		num = floor(num/10);
	}
	printf("The reverse of number %d is: %d", num, rev_num);
}
