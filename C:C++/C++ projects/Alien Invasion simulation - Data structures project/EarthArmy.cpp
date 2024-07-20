#include "EarthArmy.h"
#include "Game.h"

bool EarthArmy:: Add_unit(int type, Es*& new_solider, Et*& new_tank, Eg*& new_gunner)
{
	if (type == ES)
	{
		return Earth_soliders.Add_ES(new_solider);
	}
	else if (type == ET)
	{
		return Earth_tanks.Add_ET(new_tank);
	}
	else if (type == EG)
	{
		return Earth_gunnery.Add_EG(new_gunner);
	}

	return false;
}

bool EarthArmy:: Remove_unit(int type, Unit*& unit_removed)
{
	bool removed_success = false;
	if (type == ES)
	{
		Es* removed_solider;
		removed_success = Earth_soliders.Remove_ES(removed_solider);

		if (removed_success)
		{
			unit_removed = removed_solider;
		}

	}

	else if (type == EG)
	{
		Eg* removed_gunner;
		removed_success = Earth_gunnery.Remove_EG(removed_gunner);

		if (removed_success)
		{
			unit_removed = removed_gunner;
		}
	}

	else if (type == ET)
	{
		Et* removed_tank;
		removed_success = Earth_tanks.Remove_ET(removed_tank);

		if (removed_success)
		{
			unit_removed = removed_tank;
		}
	}
	return removed_success;
}

bool EarthArmy:: Deploy_unit(int type, Es*& solider, Et*& tank, Eg*& gunner)
{
	if (type == ES)
	{
		return Earth_soliders.Deploy_ES(solider);

	}

	else if (type == EG)
	{
		return Earth_gunnery.Deploy_EG(gunner);
	}

	else if (type == ET)
	{
		return Earth_tanks.Deploy_ET(tank);
	}
	return false;
}

void EarthArmy:: Print_Earth_army(void)
{
	Earth_soliders.Print_info();
	Earth_tanks.Print_info();
	Earth_gunnery.Print_info();
}

void EarthArmy::Attack(Game* game_ptr, LinkedQueue<Unit*>& attacked_AS, LinkedQueue<Unit*>& attacked_AM, LinkedQueue<Unit*>& attacked_AD)
{
	Es* solider;
	Et* tank;
	Eg* gunner;
	Unit* attacked_unit1;
	Unit* attacked_unit2;
	int solider_attack_capacity = 0;
	int tank_attack_capacity = 0;
	int gunner_attack_capacity = 0;
	int temp_gunner_attack_capacity = 0;
	int num_alien_soliders_by_tanks = 0; // used for attack logic of earth tanks 
	bool tanks_attacks_alien_soliders = false; // used for attack logic of earth tanks

	bool deployed_solider = false;
	bool deployed_tank = false;
	bool deployed_gunner = false;

	deployed_solider = Earth_soliders.Deploy_ES(solider);
	deployed_gunner = Earth_gunnery.Deploy_EG(gunner);
	deployed_tank = Earth_tanks.Deploy_ET(tank);


	if (deployed_solider)
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "ES " << solider->get_ID() << " Shots [ ";
		solider_attack_capacity = solider->get_Attack_capacity();
		attacked_unit1 = nullptr;
		attacked_unit2 = nullptr;
		/*Attack logic of Earth soliders*/
		for (int i = 0; i < solider_attack_capacity; i++)
		{
			bool attacked_unit_found = game_ptr->get_AlienCommandor()->Remove_unit(AS, attacked_unit1, attacked_unit2);

			if (attacked_unit_found)
			{
				if (game_ptr->get_battle_mode() == INTERACTIVE)
					cout << attacked_unit1->get_ID() << ",";

				if (attacked_unit1->get_Ta() == 0)
				{
					attacked_unit1->set_Ta(game_ptr->get_Timestep());
				}

				solider->Attack(attacked_unit1);

				attacked_AS.enqueue(attacked_unit1);
			}

			attacked_unit1 = nullptr;
			attacked_unit2 = nullptr;
		}
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "\b ]\n";
	}

	if (deployed_tank)
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "ET " << tank->get_ID() << " Shots [ ";
		tank_attack_capacity = tank->get_Attack_capacity();
		attacked_unit1 = nullptr;
		attacked_unit2 = nullptr;

		/*Attack logic of Earth tanks*/
		if (Earth_soliders.get_count() <= 0.3 * game_ptr->get_AlienCommandor()->get_units_count(AS))
		{
			tanks_attacks_alien_soliders = true;
		}
		else if (Earth_soliders.get_count() >= 0.8 * game_ptr->get_AlienCommandor()->get_units_count(AS))
		{
			tanks_attacks_alien_soliders = false;
		}


		if (tanks_attacks_alien_soliders)
		{
			num_alien_soliders_by_tanks = floor(tank_attack_capacity / 2.0);
		}

		for (int i = 0; i < tank_attack_capacity; i++)
		{
			if (num_alien_soliders_by_tanks > 0)
			{
				bool attacked_unit_found = game_ptr->get_AlienCommandor()->Remove_unit(AS, attacked_unit1, attacked_unit2);

				if (attacked_unit_found)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit1->get_ID() << ",";

					if (attacked_unit1->get_Health() == attacked_unit1->get_originalHealth())
					{
						attacked_unit1->set_Ta(game_ptr->get_Timestep());
					}

					tank->Attack(attacked_unit1);

					attacked_AS.enqueue(attacked_unit1);

					num_alien_soliders_by_tanks--;
				}
			}
			else
			{
				bool attacked_unit_found = game_ptr->get_AlienCommandor()->Remove_unit(AM, attacked_unit1, attacked_unit2);

				if (attacked_unit_found)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit1->get_ID() << ",";
					if (attacked_unit1->get_Health() == attacked_unit1->get_originalHealth())
					{
						attacked_unit1->set_Ta(game_ptr->get_Timestep());
					}

					tank->Attack(attacked_unit1);

					attacked_AM.enqueue(attacked_unit1);
				}
			}

			attacked_unit1 = nullptr;
			attacked_unit2 = nullptr;
		}
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "\b ]\n";
	}

	if (deployed_gunner)
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "EG " << gunner->get_ID() << " Shots [ ";
		gunner_attack_capacity = gunner->get_Attack_capacity();

		/*Attack logic of Earth gunners*/
		temp_gunner_attack_capacity = floor(gunner_attack_capacity / 2.0);

		for (int i = 0; i < gunner_attack_capacity; i++)
		{
			attacked_unit1 = nullptr;
			attacked_unit2 = nullptr;
			if (temp_gunner_attack_capacity >= 1)
			{
				bool attacked_unit_found = game_ptr->get_AlienCommandor()->Remove_unit(AM, attacked_unit1, attacked_unit2);

				if (attacked_unit_found)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit1->get_ID() << ",";
					if (attacked_unit1->get_Health() == attacked_unit1->get_originalHealth())
					{
						attacked_unit1->set_Ta(game_ptr->get_Timestep());
					}
					gunner->Attack(attacked_unit1);

					attacked_AM.enqueue(attacked_unit1);
					temp_gunner_attack_capacity--;
				}
			}
			else
			{
				bool attacked_unit_found = game_ptr->get_AlienCommandor()->Remove_unit(AD, attacked_unit1, attacked_unit2);

				if (attacked_unit_found)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit1->get_ID() << ",";
					if (attacked_unit1->get_Health() == attacked_unit1->get_originalHealth())
					{
						attacked_unit1->set_Ta(game_ptr->get_Timestep());
					}
					gunner->Attack(attacked_unit1);

					attacked_AD.enqueue(attacked_unit1);
				}

				if (attacked_unit2)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit2->get_ID() << ",";
					if (attacked_unit2->get_Health() == attacked_unit2->get_originalHealth())
					{
						attacked_unit2->set_Ta(game_ptr->get_Timestep());
					}
					gunner->Attack(attacked_unit2);
					attacked_AD.enqueue(attacked_unit2);
				}
				
			}
			attacked_unit1 = nullptr;
			attacked_unit2 = nullptr;
		}
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "\b ]\n";
	}

}

int EarthArmy::get_units_count(int type)
{
	if (type == ES)
	{
		return Earth_soliders.get_count();
	}
	else if (type == ET)
	{
		return Earth_tanks.get_count();
	}
	else if (type == EG)
	{
		return Earth_gunnery.get_count();
	}
	else
	{
		return 0;
	}
}