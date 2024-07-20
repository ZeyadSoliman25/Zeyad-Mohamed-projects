#include "HU.h"


Hu::Hu(int id, int type, int tj, int health, int original_health, int power, int attack_capacity) : Unit(id, type, tj, health, original_health, power, attack_capacity)
{

}

void Hu::Attack(Unit*& unit)
{

}

void Hu::Heal(Es*& solider, Et*& tank)
{
	if (solider)
	{
		solider->set_Health(this->get_Health_improvement(solider) + solider->get_Health());
	}
	else if (tank)
	{
		tank->set_Health(this->get_Health_improvement(tank) + tank->get_Health());
	}

}

int Hu::get_Health_improvement(Unit* unit)
{
	return ceil((this->get_Power() * this->get_Health() / 100.0) / sqrt(unit->get_Health() ));
}

//Copy constructor
Hu::Hu(Unit* unit) : Unit(unit)
{

}