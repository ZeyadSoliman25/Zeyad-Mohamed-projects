/*
 * main_MC1.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Zeyad Mohamed
 */
#include "lcd.h"
#include "keypad.h"
#include "uart.h"
#include "timer.h"
#include <avr/io.h>
#include <util/delay.h>


#define PASSWORD_SIZE 		5

typedef enum {
	SYSTEM_ON, SYSTEM_LOCKED, CHANGE_PASSWORD, CORRECT_PASSWORD, PASSWORD_SAVED, REENTER_PASSWORD
}instructions;

uint8 instruction_check_pass = 0;
uint8 instruction_new_pass = 0;
uint8 count_lock = 0;
uint8 system_lock = SYSTEM_LOCKED;
uint8 held_door_flag = 0;
uint8 count_door = 0;


void new_password(void){
	uint8 password_num = 0;
	uint8 i = 0;

	while (instruction_new_pass != PASSWORD_SAVED){
		LCD_clearScreen();
		LCD_moveCursor(0,0);
		LCD_displayString("plz enter pass: ");
		LCD_moveCursor(1,0);

		for (i=0; i<PASSWORD_SIZE; i++){
			password_num = KEYPAD_getPressedKey();
			LCD_displayCharacter('*');
			UART_sendByte(password_num);
			_delay_ms(30);
		}
		while (KEYPAD_getPressedKey() != '=');
		UART_sendByte('=');

		LCD_clearScreen();
		LCD_moveCursor(0,0);
		LCD_displayString("plz re-enter the");
		LCD_moveCursor(1,0);
		LCD_displayString("same pass: ");
		for (i=0; i<PASSWORD_SIZE; i++){
			password_num = KEYPAD_getPressedKey();
			LCD_displayCharacter('*');
			UART_sendByte(password_num);
			_delay_ms(30);
		}

		while (KEYPAD_getPressedKey() != '=');
		UART_sendByte('=');

		instruction_new_pass = UART_recieveByte();
	}
}


void Check_Pass(void){
	uint8 pass_num = 0;
	uint8 i = 0;

	while (instruction_check_pass != CORRECT_PASSWORD){
		LCD_clearScreen();
		LCD_moveCursor(0,0);
		LCD_displayString("plz enter pass:");
		LCD_moveCursor(1,0);
		for (i=0; i<PASSWORD_SIZE; i++){
			pass_num = KEYPAD_getPressedKey();
			LCD_displayCharacter('*');
			UART_sendByte(pass_num);
			_delay_ms(30);
		}
		while (KEYPAD_getPressedKey() != '=');
		UART_sendByte('=');
		instruction_check_pass = UART_recieveByte();

		if (instruction_check_pass == SYSTEM_LOCKED){
			break;
		}
	}
}

void lock(void){
	if (count_lock == 60){
		count_lock = 0;
		system_lock = SYSTEM_ON;
	}
	else {
		count_lock ++;
	}
}

void held(void){
	if (count_door == 15){
		held_door_flag = 1;
		count_door ++;
	}
	else if (count_door == 18){
		held_door_flag = 2;
		count_door++;
	}
	else if (count_door == 33){
		held_door_flag = 3;
		count_door = 0;
	}
	else {
		count_door++;
	}
}

int main(void){
	UART_ConfigType uart_configurations = {9600,EIGHT_BIT,DISABLED,ONE_BIT};
	Timer1_ConfigType timer1_configurations = {0,1000,FCPU_1024,CTC};

	uint8 option = 0;

	UART_init(&uart_configurations);
	Timer1_init(&timer1_configurations);

	LCD_init();

	new_password();
	instruction_new_pass = 0;

	while (1){
		LCD_clearScreen();
		LCD_moveCursor(0,0);
		LCD_displayString("+ : Open Door");
		LCD_moveCursor(1,0);
		LCD_displayString("- : Change Pass");
		option = KEYPAD_getPressedKey();

		if (option == '+'){
			UART_sendByte('+');
			Check_Pass();
			if (instruction_check_pass == SYSTEM_LOCKED){
				LCD_clearScreen();
				LCD_moveCursor(0,0);
				LCD_displayString("SYSTEM LOCKED");
				Timer1_setCallBack(lock);
				SREG |= (1<<7);
				while (system_lock != SYSTEM_ON);
				SREG &= ~(1<<7);
				instruction_check_pass = SYSTEM_ON;
			}
			else {
				LCD_clearScreen();
				LCD_moveCursor(0,0);
				LCD_displayString("Door is");
				LCD_moveCursor(1,0);
				LCD_displayString("Unlocking");
				Timer1_setCallBack(held);
				SREG |= (1<<7);
				while (held_door_flag != 1);
				while (held_door_flag != 2);
				SREG &= ~(1<<7);
				LCD_clearScreen();
				LCD_moveCursor(0,0);
				LCD_displayString("Door is");
				LCD_moveCursor(1,0);
				LCD_displayString("locking");
				SREG |= (1<<7);
				while(held_door_flag != 3);
				SREG &= ~(1<<7);
				instruction_check_pass = SYSTEM_ON;
			}
		}
		else {
			UART_sendByte('-');
			Check_Pass();
			if (instruction_check_pass == SYSTEM_LOCKED){
				LCD_clearScreen();
				LCD_moveCursor(0,0);
				LCD_displayString("SYSTEM LOCKED");
				Timer1_setCallBack(lock);
				SREG |= (1<<7);
				while (system_lock != SYSTEM_ON);
				SREG &= ~(1<<7);
				instruction_check_pass = SYSTEM_ON;
			}
			else {
				new_password();
				instruction_new_pass = 0;
				instruction_check_pass = 0;
			}
		}
	}
}
