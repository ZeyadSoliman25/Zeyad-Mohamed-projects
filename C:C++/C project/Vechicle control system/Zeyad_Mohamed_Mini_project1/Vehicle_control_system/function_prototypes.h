/*
 * =========================================================
 * Author:		Zeyad Mohamed Soliman
 * Description: Function prototypes header file
 * =========================================================
 */
#include <stdio.h>
short turn_on (); // function prototype to turn on the vehicle engine
short turn_off (); // function prototype to turn off the vehicle engine
short quit_program (); // function prototype to quit the program
char turn_on_menu ();// function prototype to display turn on menu
void traffic_light (short *vehicle_speed);  // function prototype to control the speed
void room_temperature(short *room_temp, char *ac); // function prototype to control AC
void engine_temperature(short *engine_temp, char *engine_temp_control); // function prototype to control the engine temperature
#define ENGINE_TEMP_CONTROLLER 1 //Constant definition for the conditional compilation
