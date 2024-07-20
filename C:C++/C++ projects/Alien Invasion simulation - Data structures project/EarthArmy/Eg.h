#pragma once
#include "../Unit.h"

class Eg : public Unit
{
	private:
		int Overall_power = 0;

	public:
		/*to be implemented in phase 2*/
		void Attack(Unit*& attacked_unit);

		/*Overall power is an indication of how strong the gunner is , as it will be used as a priority to sort the PriQueue*/
		int get_Overall_Power();

		/*Setter to be used when removing an earth gunner from its list*/
		void set_Overall_Power(int eg_Overall_Power);

		//Non-default constructor
		Eg(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

		//Copy constructor
		Eg(Unit* unit);
};