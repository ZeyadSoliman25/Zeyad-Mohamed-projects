/*
 * q20.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main()
{
	int i = 0 , h,j;
	for (i = 1 ; i<= 5 ; i++){
		for (h=5 ; h>=i ; h--){
			printf(" ");
		}
		for (j=1 ; j<= 2*i - 1 ; j++){
			printf("*");
		}
		printf("\n");
	}
}
