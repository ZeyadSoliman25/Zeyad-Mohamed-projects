#pragma once

#include "../DS/LinkedQueue.h"
#include "../DS/priQueue.h"
#include "Et.h"
#include "Es.h"

class Game;

class Uml_list
{
	private:
		LinkedQueue<Et*> Damaged_tanks;
		priQueue<Es*> Damaged_soliders;
		int max_earth_health_limit;
		int count_damaged_soliders;
		int count_damaged_tanks;

	public:
		bool Add_Damaged_Tank(Et*& tank, Game* game_ptr);

		bool Add_Damaged_solider(Es*& solider, Game* game_ptr);

		bool remove_solider(Es*& solider);

		bool remove_tank(Et*& tank);

		void set_count_damaged_soliders(int count);

		void set_count_damaged_tanks(int count);

		int get_count_damaged_soliders(void);

		int get_count_damaged_tanks(void);
		void set_max_earth_health_limit(int max_health);

		void Print_Uml_list(void);
};

