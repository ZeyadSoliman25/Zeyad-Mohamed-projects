/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Turn off vehicle engine source code
 * =========================================================
 */
#include <stdio.h>

short turn_off (){
	char choice;
	short program_choice = 0;
	printf("Turned off vehicle engine\n\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c",&choice);
	program_choice = (short)choice - 97;
	return program_choice;
}
