#pragma once
#include "../Unit.h"


class Ad : public Unit
{
	public:
		void Attack(Unit*& attacked_unit);

		//Non-default constructor
		Ad(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

		//Copy constructor
		Ad(Unit* unit);
};

