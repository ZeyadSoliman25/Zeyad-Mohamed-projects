/*
 * q10.c
 *
 *  Created on: Aug 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

void upper_lower(char *string);

int main(){
	char string[10]={};
	printf("Enter a word: ");
	scanf("%s",string);
	upper_lower(string);
}

void upper_lower(char *string){
	int i = 0;
	for (i = 0;i < 10; i++){
		if (string[i] >= 65 && string[i] <=90){
			string[i]+=32;
		}
	}
	printf("%s",string);
}
