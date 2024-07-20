/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Turn on vehicle engine source code
 * =========================================================
 */

#include <stdio.h>
#include <string.h>
#include "function_prototypes.h"

/* main turn on function */
short turn_on (){
	char ac[5] = "OFF"; //initial status of AC
	char func_choice;// choice taken in the function
	short vehicle_speed = 0;

	#if ENGINE_TEMP_CONTROLLER
		char engine_temp_control[5] = "OFF";//status of engine temperature control
		short engine_temp = 90;
	#endif

	short room_temp = 25;
	short program_choice = 0;// variable to modify the function choice and be passed to the main function

	func_choice = turn_on_menu();

	while (func_choice != 'a'){
		switch (func_choice){
		case 'b':
			traffic_light(&vehicle_speed);
			break;
		case 'c':
			room_temperature(&room_temp,ac);
			break;
		case 'd':

			#if ENGINE_TEMP_CONTROLLER
				engine_temperature(&engine_temp,engine_temp_control);
			#else
				printf("Wrong input!\n");
			#endif

			break;
		}
		if (vehicle_speed == 30){
			strcpy(ac,"ON");
			room_temp = room_temp * 5/4 + 1;

			// To check if the room temperature went over the specified limit
			if (room_temp > 30){
				room_temp = 20;
			}

			#if ENGINE_TEMP_CONTROLLER
				strcpy(engine_temp_control,"ON");
				engine_temp = engine_temp * 5/4 + 1;

				// To check if the engine temperature went over the limit
				if (engine_temp > 150){
					engine_temp = 125;
				}
			#endif

		}
		printf("\nEngine is: ON\n");
		printf("AC is: %s\n", ac);
		printf("Vehicle speed: %hi km/hr\n", vehicle_speed);
		printf("Room temperature: %hi C\n",room_temp);

		#if ENGINE_TEMP_CONTROLLER
			printf("Engine temperature control: %s\n",engine_temp_control);
			printf("Engine temperature: %hi C\n\n",engine_temp);
		#endif

		func_choice = turn_on_menu();
		}
	printf("Turned off vehicle engine\n\n");
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	scanf(" %c",&func_choice);
	program_choice = (short)func_choice - 97;// modify the choice to a integer to be passed back to the main function
	return program_choice;
}
