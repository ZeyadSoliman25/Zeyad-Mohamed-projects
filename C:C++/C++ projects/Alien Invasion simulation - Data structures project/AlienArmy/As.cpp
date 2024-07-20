#include "As.h"

void As:: Attack(Unit*& attacked_unit)
{
	attacked_unit->set_Health(attacked_unit->get_Health() - this->get_damage(attacked_unit));
}

As::As(int id, int type, int tj, int health, int original_health, int power, int attack_capacity) : Unit(id, type, tj, health, original_health, power, attack_capacity)
{

}

As::As(Unit* unit) : Unit(unit)
{

}