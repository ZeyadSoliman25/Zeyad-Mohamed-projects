#pragma once
#include <iostream>
#include <cmath>
#include "enums.h"

class Unit
{
private:
	int ID; //ID of the unit 
	int Type; //Type of the unit
	int Tj; //Join time of the unit 
	int Ta; //First attacked time of the unit 
	int Td; //Destruction time of the unit 
	int joined_UML; //time the unit joined the unit maintenance list 
	int OriginalHealth; //Original health of the unit
	int Health; //current health of the unit
	int Power; //power of the unit
	int Attack_Capacity; //attack capacity of the unit

public:
	virtual void set_ID(int id);

	virtual void set_Type(int type);

	virtual void set_Tj(int tj); //set the the join time of the unit

	virtual void set_Ta(int ta); // set first attacked time of the unit

	virtual void set_Td(int td); // set the destruction time of the unit

	virtual void set_joined_UML(int join_time); // set the join time of the unit maintenance list 

	virtual void set_OriginalHealth(int health); // set the original health of the	unit

	virtual void set_Health(int health);

	virtual void set_Power(int power);

	virtual void set_Attack_Capacity(int attack_cap);

	virtual int get_ID(void);

	virtual int get_Type(void);

	virtual int get_Tj(void);

	virtual int get_Td(void);

	virtual int get_Ta(void);

	virtual int get_joined_UML(void);

	virtual int get_Df(void); //return first attack delay time of the unit

	virtual int get_Dd(void); // return destruction delay time of the unit

	virtual int get_Db(void); // returns battle time of the unit 

	virtual int get_Power(void);

	virtual int get_originalHealth(void); 

	virtual int get_Health(void);

	virtual int get_Attack_capacity(void);
	virtual int get_damage(Unit* unit2);

	virtual void Attack(Unit*& attacked_unit) = 0; //Pure virtual Attack function so the children classes can each implement it properly

	// non-default constructor to initialize all the needed data members 
	Unit(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

	//copy constructor
	Unit(Unit* copy_unit);
};