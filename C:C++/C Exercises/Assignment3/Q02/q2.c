/*
 * q2.c
 *
 *  Created on: Jul 30, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>

#define SIZE 10

int check_characters (int str_size, char *str);


int main (){
	char string [SIZE] = {};
	int result = 0;
	printf("Enter a string: ");
	gets(string);
	result = check_characters(SIZE, string);
	printf("%d\n", result);
}


int check_characters(int str_size, char *str){
	int i = 0;
	int result = 1;
	while (str[i]!='\0'){
		int j = i+1;
		while (str[j] != '\0'){
			if (str[i]==str[j]){
				result = 0;
			}
			j++;
		}
		i++;
	}
	return result;
}
