/*
 * q12.c
 *
 *  Created on: Aug 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int length (char *string);


int main(){
	char string[10]={};
	int len = 0;
	printf("Enter a word: ");
	scanf("%s",string);
	len = length(string);
	printf("The length of the string = %d", len);
}

int length (char *string){
	int i = 0;
	while (string[i] != '\0'){
		i++;
	}
	return i;
}
