/*
 * q8.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
#include <math.h>
int main(){
	double num = 0;
	double p_num = 0;
	printf("Enter a number: ");
	scanf("%lf", &num);
	p_num = remainder(num, sqrt(num));
	if (p_num == 0){
		printf("The number is a perfect square.");
	}
	else {
		printf("The number is not a perfect square.");
	}
}
