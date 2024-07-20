#pragma once
#include "AlienArmy/Ad_list.h"
#include "AlienArmy/Am_list.h"
#include "AlienArmy/As_list.h"
#include "DS/ArrayStack.h"

class Game;

class AlienArmy
{
	private:
		Ad_list Alien_drones;
		Am_list Alien_monsters;
		As_list Alien_soliders;

	public:
		bool Add_unit(int type, As*& new_solider, Am*& new_monster, Ad*& new_drone);

		bool Remove_unit(int type, Unit*& unit_removed, Unit*& unit_removed2);

		bool Deploy_unit(int type, As*& new_solider, Am*& new_monster, Ad*& new_drone1, Ad*& new_drone2);

		int get_units_count(int type);
		void Print_Alien_army(void);

		void Attack(Game* game_ptr, LinkedQueue<Unit*>& attacked_ES, ArrayStack<Unit*>& attacked_ET, LinkedQueue<Unit*>& attacked_EG);
};

