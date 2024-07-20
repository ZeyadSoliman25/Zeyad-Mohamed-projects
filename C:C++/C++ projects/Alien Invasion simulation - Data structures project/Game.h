#pragma once
#include "AlienArmy.h"
#include "EarthArmy.h"
#include "EarthArmy/Uml_list.h"
#include "EarthArmy/Hu_list.h"
#include "RandGen.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>


class Game
{
private:
	EarthArmy EarthCommandor;
	AlienArmy AlienCommandor;
	Hu_list healers; // heal units in the earth army 
	Uml_list damaged_units; // damaged units in the maintenance list 
	RandGen generator;
	LinkedQueue<Unit*> Killed_List;
	int killed_units_count;
	int healed_units_count;
	int Timestep;
	int Total_Es;
	int Total_Et;
	int Total_Eg;
	int Total_As;
	int Total_Am;
	int Total_Ad;
	int battle_result;
	int battle_mode;

public:
	void LoadFromFile(string filename);

	void GenerateOutputFile(string filename); //generates output file using formated given in the document
	EarthArmy* get_EarthCommandor(void); //return a pointer to the earth commandor in the game class 
	AlienArmy* get_AlienCommandor(void); // return a pointer to the alien commandor in the game class
	RandGen* get_generator(void); // return a pointer to the generator in the game class

	Hu_list* get_Healers(void); // return Hu list

	Uml_list* get_damaged_units(void); // return UML list

	void heal_damaged_Earth_units(void); // heal damaged earth units

	bool Add_to_killed_list(Unit*& killed_unit); // to add killed unit to the killed list 

	bool Add_to_heal_list(Hu*& heal_unit); // to add heal unit to the healers list

	bool Remove_heal_unit(Hu*& heal); // remove heal unit from the healers list

	void Check_killed_UML(void); // check the units that are supposed to be killed in the UML after 10 timesteps

	void set_Timestep(int time); // to set the timestep

	int get_Timestep(void); // return the current timestep

	void set_Total_Es(int num_Es); // set the total Es 
	void set_Total_Et(int num_Et); // set the total Et 
	void set_Total_Eg(int num_Eg); // set the total Eg 
	void set_Total_As(int num_As); // set the total As 
	void set_Total_Am(int num_Am); // set the total Am 
	void set_Total_Ad(int num_Ad); // set the total Ad

	void set_battle_mode(int mode);

	int get_Total_Es(void); // get the total Es
	int get_Total_Et(void); // get the total Et
	int get_Total_Eg(void); // get the total Eg
	int get_Total_As(void); // get the total As
	int get_Total_Am(void); // get the total Am
	int get_Total_Ad(void); // get the total Ad

	int get_battle_mode(void); // get the battle mode

	void Armies_Attack(void); //To make each army attack the other 

	void check_winner(void); // check the winner of battle

	int get_battle_result(void); // get the result of the battle
	void Print_armies(void); // print all units in both armies

	void Print_heal_list(void); // prints the healers list

	void Print_Uml_list(void); // prints the UML list

	void Print_Killed_list(void); // to print the list of killed units in each timestep

	Game();
	~Game();

	// void Attack(void); // To be implemented in phase 2
};