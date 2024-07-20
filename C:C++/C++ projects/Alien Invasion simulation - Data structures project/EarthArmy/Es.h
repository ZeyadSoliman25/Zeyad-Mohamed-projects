#pragma once
#include "../Unit.h"


class Es : public Unit
{
	public:
		void Attack(Unit*& attacked_unit);

		//Non-default constructor
		Es(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

		//Copy constructor
		Es(Unit* unit);
};