/*
 * q9.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int grade = 0 ;
	printf ("Enter your grade: ");
	scanf("%d", &grade);
	if (grade >= 85){
		printf("Excellent");
	}
	else if (grade >= 75 && grade <= 85) {
		printf("Very good");
	}
	else if (grade >= 65 && grade <= 75){
		printf("Good");
	}
	else if (grade == 50){
		printf("Pass");
	}
	else {
		printf("Fail");
	}
}
