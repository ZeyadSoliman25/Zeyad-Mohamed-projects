/*
 * q11.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int result = 0 ;
	int i = 0;
	for (i=1; i<=100; i++){
		result += i;
	}
	printf("The summation of first 100 intergers is: %d", result);
}
