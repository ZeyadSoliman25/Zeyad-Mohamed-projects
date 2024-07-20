/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Vehicle control system turn on menu source code
 * =========================================================
 */

#include <stdio.h>
#include "function_prototypes.h"

char turn_on_menu (){
	char choice = 0;
	printf("a. turn off the engine\n");
	printf("b. set the traffic light color\n");
	printf("c. set the room temperature(sensor)\n");
	#if ENGINE_TEMP_CONTROLLER
		printf("d. set the engine temperature\n");
	#endif
	scanf(" %c",&choice);
	return choice;
}
