#include "Unit.h"


void Unit:: set_ID(int id)
{
	if (id > 0)
	{
		ID = id;
	}
}

void Unit:: set_Type(int type)
{
	if (type >= 0)
	{
		Type = type;
	}
}

void Unit:: set_Tj(int tj) //set the the join time of the unit
{
	if (tj > 0)
	{
		Tj = tj;
	}
}

void Unit:: set_Ta(int ta) // set first attacked time of the unit
{
	if (ta >= 0)
	{
		Ta = ta;
	}
}

void Unit:: set_Td(int td) // set the destruction time of the unit
{
	if (td >= 0)
	{
		Td = td;
	}
}

void Unit::set_joined_UML(int join_time)
{
	if (join_time > 0)
	{
		joined_UML = join_time;
	}
}

void Unit::set_OriginalHealth(int health)
{
	if (health > 0)
	{
		OriginalHealth = health;
	}
	else
	{
		OriginalHealth = 0;
	}
}

void Unit:: set_Health(int health)
{
	if (health > 0)
	{
		Health = health;
	}
	else
	{
		Health = 0;
	}
}

void Unit:: set_Power(int power)
{
	if (power > 0)
	{
		Power = power;
	}
}

void Unit:: set_Attack_Capacity(int attack_cap)
{
	if (attack_cap > 0)
	{
		Attack_Capacity = attack_cap;
	}
}

int Unit:: get_ID(void)
{
	return ID;
}

int Unit:: get_Type(void)
{
	return Type;
}

int Unit:: get_Tj(void)
{
	if (Tj >= 0)
	{
		return Tj;
	}
	else
	{
		return -1;
	}
}

int Unit:: get_Td(void)
{
	if (Td >= 0)
	{
		return Td;
	}
	else
	{
		return -1;
	}
}

int Unit::get_Ta(void)
{
	if (Ta >= 0)
	{
		return Ta;
	}
	else
	{
		return -1;
	}
}

int Unit::get_joined_UML(void)
{
	if (joined_UML > 0)
	{
		return joined_UML;
	}
	else
	{
		return 0;
	}
}

int Unit:: get_Df(void) //return first attack delay time of the unit
{
	if (Ta != 0)
	{
		return Ta - Tj;
	}
	else
	{
		return -1;
	}
}

int Unit:: get_Dd(void) // return destruction delay time of the unit
{
	if ((Td != 0) && (Ta != 0))
	{
		return Td - Ta;
	}
	else
	{
		return -1;
	}
}

int Unit:: get_Db(void) // returns battle time of the unit 
{
	if (Td != 0)
	{
		return Td - Tj;
	}
	else
	{
		return -1;
	}
}

int Unit:: get_Power(void)
{
	return Power;
}

int Unit::get_originalHealth(void)
{
	return OriginalHealth;
}

int Unit:: get_Health(void)
{
	return Health;
}

int Unit:: get_Attack_capacity(void)
{
	return Attack_Capacity;
}

int Unit:: get_damage(Unit* unit2)
{
	return ceil(( Power * (Health / 100.0)) / sqrt(unit2->get_Health()));
}

// non-default constructor to initialize all the needed data members 
Unit:: Unit(int id, int type, int tj, int health, int original_health, int power, int attack_capacity)
{
	set_ID(id);
	set_Type(type);
	set_Tj(tj);
	set_OriginalHealth(original_health);
	set_Health(health);
	set_Power(power);
	set_Attack_Capacity(attack_capacity);
	Ta = 0;
	Td = 0;
	joined_UML = 0;
}

//copy constructor
Unit::Unit(Unit* copy_unit)
{
	this->set_ID(copy_unit->get_ID());
	this->set_Type(copy_unit->get_Type());
	this->set_Tj(copy_unit->get_Tj());
	this->set_Td(copy_unit->get_Td());
	this->set_Ta(copy_unit->Ta);
	this->set_OriginalHealth(copy_unit->get_originalHealth());
	this->set_Health(copy_unit->get_Health());
	this->set_Power(copy_unit->get_Power());
	this->set_Attack_Capacity(copy_unit->get_Attack_capacity());
	this->set_joined_UML(copy_unit->get_joined_UML());
}