#pragma once
#include "Es.h"
#include "Et.h"

class Hu : public Unit
{

	public:
		Hu(int id, int type, int tj, int health, int original_health, int power, int attack_capacity);

		void Attack(Unit*& unit); // to implemented as Heal function but changing the name for more realistic usage

		void Heal(Es*& solider, Et*& tank);

		int get_Health_improvement(Unit* unit); //return the health improvement of the Health unit

		//Copy constructor
		Hu(Unit* unit);

};

