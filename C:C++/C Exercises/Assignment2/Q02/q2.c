/*
 * q2.c
 *
 *  Created on: Jul 20, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	char x = 0 ;
	printf("Enter a character: ");
	scanf("%c", &x);
	if ( (x>=65 && x<=90) || (x>=97 && x<=122) ){
		printf("The character is an alphabet");
	}
	else {
		printf("The character isnot an alphabet");
	}
}

