/*
 * q19.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main()
{
	int i = 0,j;
	for (i = 1 ; i<= 5 ; i++){
		for (j=5 ; j>=i ; j--){
			printf(" *");
		}
		printf("\n");
	}
}
