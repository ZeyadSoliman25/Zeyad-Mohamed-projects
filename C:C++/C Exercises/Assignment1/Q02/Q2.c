/*
 * Q2.c
 *
 *  Created on: Jul 4, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	char name[10];
	char grade;
	printf("Enter your name and grade: ");
	scanf("%s \n", name);
	scanf("%c", &grade);
	printf("Hello %s \n",name);
	printf("Nice %c grade champ\n",grade);

}
