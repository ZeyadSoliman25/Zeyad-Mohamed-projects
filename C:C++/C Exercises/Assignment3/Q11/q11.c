/*
 * q11.c
 *
 *  Created on: Aug 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

int frequency_char (char *string, char character);


int main(){
	char string[10]={};
	char character = 0;
	int freq = 0;
	printf("Enter a word: ");
	scanf("%s", string);
	printf("\nEnter the searched character: ");
	scanf(" %c",&character);
	freq = frequency_char(string,character);
	printf("The frequency of %c = %d", character, freq);
}


int frequency_char (char *string, char character){
	char counter = 0;
	int i = 0;
	for (i = 0; i <10 ; i++){
		if (string[i] == character){
			counter++;
		}
	}
	return counter;
}
