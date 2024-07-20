#include "Ad.h"


void Ad::Attack(Unit*& attacked_unit)
{
	attacked_unit->set_Health(attacked_unit->get_Health() - this->get_damage(attacked_unit));
}

//Non-default constructor
Ad::Ad(int id, int type, int tj, int health, int original_health, int power, int attack_capacity) : Unit(id, type, tj, health, original_health, power, attack_capacity)
{

}

//Copy constructor
Ad::Ad(Unit* unit) : Unit(unit)
{

}