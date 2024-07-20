#pragma once
#pragma once
#include "../Unit.h"


class As : public Unit
{
public:
	void Attack(Unit*& attacked_unit);

	As(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

	As(Unit* unit);
};
