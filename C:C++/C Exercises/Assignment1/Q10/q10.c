/*
 * q10.c
 *
 *  Created on: Jul 6, 2023
 *      Author: zayedsoliman
 */

#include <stdio.h>
int main(){
	float num1 = 0;
	float num2 = 0;
	float result= 0;
	char op;
	printf("Enter operation(+ ,- ,* ,/):");
	scanf("%c", &op);
	printf("Enter two numbers: ");
	scanf("%f %f", &num1, &num2);

	switch (op){
	case '+':
		result = num1 + num2 ;
		printf("The result = %f", result);
		break;
	case '-':
		result = num1 - num2;
		printf("The result = %f", result);
		break;
	case '*':
		result = num1 * num2;
		printf("The result = %f", result);
		break;
	case '/':
		result = num1 / num2;
		printf("The result = %.4f", result);
		break;
	}

}
