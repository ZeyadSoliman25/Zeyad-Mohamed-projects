#pragma once
#include "EarthArmy/Eg_list.h"
#include "EarthArmy/Es_list.h"
#include "EarthArmy/Et_list.h"


class Game;

class EarthArmy
{
	private:
		Eg_list Earth_gunnery;
		Es_list Earth_soliders;
		Et_list Earth_tanks;

	public:
		bool Add_unit(int type, Es*& new_solider, Et*& new_tank, Eg*& new_gunner);
		bool Remove_unit(int type, Unit*& unit_removed);
		bool Deploy_unit(int type, Es*& solider, Et*& tank, Eg*& gunner);

		int get_units_count(int type);
		void Print_Earth_army(void);
		void Attack(Game* game_ptr, LinkedQueue<Unit*>& attacked_AS, LinkedQueue<Unit*>& attacked_AM, LinkedQueue<Unit*>& attacked_AD);
};