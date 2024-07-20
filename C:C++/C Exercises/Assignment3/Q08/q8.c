/*
 * q8.c
 *
 *  Created on: Aug 4, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

void geo_series(int number);

int main(){
	int number = 0;
	printf("Enter a number: ");
	scanf("%d",&number);
	geo_series(number);
}

void geo_series(int number){
	int i = 0;
	int num = 1;
	for (i=0;i<number;i++){
		num *=3;
	}
	printf("%d", num);
}
