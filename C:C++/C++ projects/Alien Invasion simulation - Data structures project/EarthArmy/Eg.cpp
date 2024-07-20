#include "Eg.h"

void Eg:: Attack(Unit*& attacked_unit)
{
	attacked_unit->set_Health(attacked_unit->get_Health() - this->get_damage(attacked_unit));
}

/*Overall power is an indication of how strong the gunner is , as it will be used as a priority to sort the PriQueue*/
int Eg:: get_Overall_Power()
{
	return Overall_power;
}

/*Setter to be used when removing an earth gunner from its list*/
void Eg:: set_Overall_Power(int eg_Overall_Power)
{
	if (eg_Overall_Power > 0)
	{
		Overall_power = eg_Overall_Power;
	}
	else
	{
		Overall_power = 0;
	}
}

//Non-default constructor
Eg :: Eg (int id, int type, int tj, int health, int original_health, int power, int attack_capacity) : Unit(id, type, tj, health, original_health, power, attack_capacity)
{
	set_Overall_Power((int)ceil((get_Power() + get_Health()) / 2.0));
}

//Copy constructor
Eg :: Eg (Unit* unit) : Unit(unit)
{
	set_Overall_Power((get_Power() + get_Health()) / 2);
}