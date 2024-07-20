#pragma once
#include "../Unit.h"


class Et : public Unit
{
	public:
		void Attack(Unit*& attacked_unit);

		//Non-default constructor
		Et(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

		//Copy constructor
		Et(Unit* unit);
};