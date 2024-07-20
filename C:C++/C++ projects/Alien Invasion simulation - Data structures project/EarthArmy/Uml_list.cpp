#include <iostream>
#include "Uml_list.h"
#include "../Game.h"

using namespace std;

bool Uml_list::Add_Damaged_solider(Es*& solider, Game* game_ptr)
{
	bool insert_success = false;

	if (solider)
	{
		this->set_max_earth_health_limit(game_ptr->get_generator()->get_max_earth_health_limit());
		int solider_priority = max_earth_health_limit - solider->get_Health();
		Damaged_soliders.enqueue(solider, solider_priority);
		insert_success = true;
		count_damaged_soliders++;
	}

	return insert_success;
}

bool Uml_list::Add_Damaged_Tank(Et*& tank, Game* game_ptr)
{
	count_damaged_tanks++;

	return Damaged_tanks.enqueue(tank);
}

bool Uml_list::remove_tank(Et*& tank)
{
	count_damaged_tanks--;
	return Damaged_tanks.dequeue(tank);
}

bool Uml_list::remove_solider(Es*& solider)
{
	if (count_damaged_soliders == 0)
		return false;

	int pri;
	count_damaged_soliders--;
	return Damaged_soliders.dequeue(solider, pri);
}

void Uml_list::set_count_damaged_soliders(int count)
{
	if (count > 0)
	{
		count_damaged_soliders = count;
	}
}

void Uml_list::set_count_damaged_tanks(int count)
{
	if (count > 0)
	{
		count_damaged_tanks = count;
	}
}

int Uml_list::get_count_damaged_tanks(void)
{
	return count_damaged_tanks;
}

int Uml_list::get_count_damaged_soliders(void)
{
	return count_damaged_soliders;
}

void Uml_list::set_max_earth_health_limit(int max_health)
{
	if (max_health > 0)
	{
		max_earth_health_limit = max_health;
	}
}

void Uml_list::Print_Uml_list(void)
{
	LinkedQueue<Et*> temp_damaged_tanks = Damaged_tanks;
	priQueue<Es*> temp_damaged_soliders = Damaged_soliders;
	Es* temp_solider = nullptr;
	Et* temp_tank = nullptr;
	int pri = 0;

	if ( (count_damaged_soliders+count_damaged_tanks) > 0)
	{
		cout << count_damaged_soliders + count_damaged_tanks << " UML" << " [ ";

		for (int i = 0; i < count_damaged_soliders; i++)
		{
			temp_damaged_soliders.dequeue(temp_solider, pri);
			cout << temp_solider->get_ID() << ",";
		}
		for (int i = 0; i < count_damaged_tanks; i++)
		{
			temp_damaged_tanks.dequeue(temp_tank);
			cout << temp_tank->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " UML" << "[ ]" << endl;
	}
}