/*
 * q4.c
 *
 *  Created on: Jul 20, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	int num1 = 0;
	int num2 = 0;
	int result = 0;
	char op = 0;
	printf("Enter the operation (+,-,*,/): ");
	scanf("%c", &op);
	printf("Enter two numbers: ");
	scanf("%d %d", &num1 ,&num2);

	switch (op){
	case '+':
		result = num1 + num2 ;
		printf("The result is: %d", result);
		break;
	case '-':
		result = num1 - num2;
		printf("The result is: %d", result);
		break;
	case '*':
		result = num1 * num2;
		printf("The result is: %d", result);
		break;
	case '/':
		result = num1 / num2;
		printf("The result is: %d", result);
		break;
	default:
		printf("This is not a valid operation.");
	}

}
