/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Vehicle control system main source code
 * =========================================================
 */

#include <stdio.h>

#include "function_prototypes.h" // header file of the function prototypes used in the project
#define ON 0
#define OFF 1
#define QUIT 2

int main(){
	char user_choice = 0; // variable declaration for user's choice
	short (*func_ptr[3])() = {turn_on,turn_off,quit_program}; // array of pointers to functions of the system
	short program_choice = 0;

	/* choice selection of the user */
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c",&user_choice);

	program_choice = (short)user_choice - 97; //to modify the user_choice to get along with the offsets of the array of pointers

	/* In case the user enter a wrong input */
	while (program_choice > QUIT || program_choice < ON ){
		printf("Wrong input!\n");
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		scanf(" %c",&user_choice);
		program_choice = (short)user_choice - 97;

	}
	/* in case the user chose to quit the program first */
	if (program_choice == QUIT){
		program_choice = (*func_ptr[program_choice])();
	}

	/* to keep the program running according to the user choice*/
	while (program_choice != QUIT ){
		program_choice = (*func_ptr[program_choice])();

		/* if the user chose to quit the system */
		if (program_choice == QUIT){
			program_choice = (*func_ptr[program_choice])();
		}
	}
}
