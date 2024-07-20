#pragma once
#include "../Unit.h"

class Am : public Unit
{
	public:
		void Attack(Unit*& attacked_unit);

		//Non-default constructor
		Am(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

		//Copy constructor
		Am(Unit* unit);

};

