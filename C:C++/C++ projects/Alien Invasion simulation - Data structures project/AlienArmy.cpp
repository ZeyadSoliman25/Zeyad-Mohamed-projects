#include "AlienArmy.h"
#include "Game.h"

bool AlienArmy::Add_unit(int type, As*& new_solider, Am*& new_monster, Ad*& new_drone)
{

	if (type == AS)
	{
		return Alien_soliders.Add_AS(new_solider);
	}
	else if (type == AM)
	{
		return Alien_monsters.Add_AM(new_monster);
	}
	else if (type == AD)
	{
		return Alien_drones.Add_AD_front(new_drone);

	}

	return false;
}

bool AlienArmy::Remove_unit(int type, Unit*& unit_removed, Unit*& unit_removed2)
{
	bool removed_success = false;
	if (type == AS)
	{
		As* removed_solider;
		removed_success = Alien_soliders.Remove_AS(removed_solider);

		if (removed_success)
		{
			unit_removed = removed_solider;
			unit_removed2 = nullptr;
		}

	}

	else if (type == AM)
	{
		Am* removed_monster;
		removed_success = Alien_monsters.Remove_AM(removed_monster);

		if (removed_success)
		{
			unit_removed = removed_monster;
			unit_removed2 = nullptr;
		}
	}

	else if (type == AD)
	{
		Ad* removed_drone1;
		Ad* removed_drone2;
		removed_success = Alien_drones.Remove_AD(removed_drone1, removed_drone2);

		if (removed_success)
		{
			unit_removed = removed_drone1;
			unit_removed2 = removed_drone2;
		}
	}
	return removed_success;
}

bool AlienArmy::Deploy_unit(int type, As*& solider, Am*& monster, Ad*& drone1, Ad*& drone2)
{
	if (type == AS)
	{
		return Alien_soliders.Deploy_AS(solider);
	}
	else if (type == AD)
	{
		bool deployed_success = false;
		bool deployed_success_2 = false;
		deployed_success = Alien_drones.Deploy_AD_front(drone1);
		deployed_success_2 = Alien_drones.Deploy_AD_rear(drone2);

		if (deployed_success && deployed_success_2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (type == AM)
	{
		return Alien_monsters.Remove_AM(monster);
	}
}

int AlienArmy::get_units_count(int type)
{
	if (type == AS)
	{
		return Alien_soliders.get_count();
	}
	else if (type == AM)
	{
		return Alien_monsters.get_count();
	}
	else if (type == AD)
	{
		return Alien_drones.get_count();
	}
	else
	{
		return 0;
	}
}

void AlienArmy::Print_Alien_army(void)
{
	Alien_soliders.Print_info();
	Alien_monsters.Print_info();
	Alien_drones.Print_info();
}

void AlienArmy::Attack(Game* game_ptr, LinkedQueue<Unit*>& attacked_ES, ArrayStack<Unit*>& attacked_ET, LinkedQueue<Unit*>& attacked_EG)
{
	As* solider = nullptr;
	Am* monster = nullptr;
	Ad* drone1 = nullptr;
	Ad* drone2 = nullptr;

	Unit* attacked_unit = nullptr;

	int solider_attack_capacity = 0;
	int monster_attack_capacity = 0;
	int temp_monster_attack_capacity = 0;
	int drone1_attack_capacity = 0;
	int drone2_attack_capacity = 0;
	int temp_drone_attack_capacity = 0;
	int drones_attack_capacity = 0;

	bool deployed_solider = false;
	bool deployed_monster = false;
	bool deployed_drone1 = false;
	bool deployed_drone2 = false;

	deployed_solider = Alien_soliders.Deploy_AS(solider);
	deployed_monster = Alien_monsters.Remove_AM(monster);
	deployed_drone1 = Alien_drones.Deploy_AD_front(drone1);
	deployed_drone2 = Alien_drones.Deploy_AD_rear(drone2);

	if (deployed_solider)
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "AS " << solider->get_ID() << " Shots [ ";
		solider_attack_capacity = solider->get_Attack_capacity();
		attacked_unit = nullptr;
		/*Attack logic of alien solider*/
		for (int i = 0; i < solider_attack_capacity; i++)
		{
			game_ptr->get_EarthCommandor()->Remove_unit(ES, attacked_unit);

			if (attacked_unit)
			{
				if (game_ptr->get_battle_mode() == INTERACTIVE)
					cout << attacked_unit->get_ID() << ",";
				if (attacked_unit->get_Health() == attacked_unit->get_originalHealth())
				{
					attacked_unit->set_Ta(game_ptr->get_Timestep());
				}

				solider->Attack(attacked_unit);


				attacked_ES.enqueue(attacked_unit);
			}

			attacked_unit = nullptr;
		}
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "\b ]\n";

	}

	if (deployed_monster)
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "AM " << monster->get_ID() << " Shots [ ";
		attacked_unit = nullptr;
		monster_attack_capacity = monster->get_Attack_capacity();

		/*Attack logic of monsters*/
		temp_monster_attack_capacity = floor(monster_attack_capacity / 2.0);

		for (int i = 0; i < monster_attack_capacity; i++)
		{
			if (temp_monster_attack_capacity > 0)
			{
				game_ptr->get_EarthCommandor()->Remove_unit(ES, attacked_unit);

				if (attacked_unit)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit->get_ID() << ",";
					if (attacked_unit->get_Health() == attacked_unit->get_originalHealth())
					{
						attacked_unit->set_Ta(game_ptr->get_Timestep());
					}

					monster->Attack(attacked_unit);

					attacked_ES.enqueue(attacked_unit);
					temp_monster_attack_capacity--;
				}
			}
			else
			{
				game_ptr->get_EarthCommandor()->Remove_unit(ET, attacked_unit);

				if (attacked_unit)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit->get_ID() << ",";
					if (attacked_unit->get_Health() == attacked_unit->get_originalHealth())
					{
						attacked_unit->set_Ta(game_ptr->get_Timestep());
					}

					monster->Attack(attacked_unit);

					attacked_ET.push(attacked_unit);
				}
			}

			attacked_unit = nullptr;
		}
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "\b ]\n";
		As* temp_solider = nullptr;
		Ad* temp_drone = nullptr;
		this->Add_unit(AM, temp_solider, monster, temp_drone);
	}

	if ( (deployed_drone1 && deployed_drone2) && (drone1->get_ID() != drone2->get_ID()) )
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "AD " << drone1->get_ID() << " & AD "<< drone2->get_ID() << " Shots [ ";
		attacked_unit = nullptr;
		drone1_attack_capacity = drone1->get_Attack_capacity();
		drone2_attack_capacity = drone2->get_Attack_capacity();

		/*attack logic of alien drones*/
		if (drone1_attack_capacity >= drone2_attack_capacity)
		{
			temp_drone_attack_capacity = floor(drone2_attack_capacity / 2.0);
			drones_attack_capacity = drone2_attack_capacity;
		}
		else if (drone2_attack_capacity > drone1_attack_capacity)
		{
			temp_drone_attack_capacity = floor(drone1_attack_capacity / 2.0);
			drones_attack_capacity = drone1_attack_capacity;
		}

		for (int i = 0; i < drones_attack_capacity; i++)
		{
			if (temp_drone_attack_capacity >= 1)
			{
				bool removed_success = game_ptr->get_EarthCommandor()->Remove_unit(ET, attacked_unit);

				if (removed_success)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit->get_ID() << ",";
					if (attacked_unit->get_Health() == attacked_unit->get_originalHealth())
					{
						attacked_unit->set_Ta(game_ptr->get_Timestep());
					}

					drone1->Attack(attacked_unit);
					drone2->Attack(attacked_unit);

					attacked_ET.push(attacked_unit);
				}

				temp_drone_attack_capacity--;
			}
			else
			{
				bool removed_success = game_ptr->get_EarthCommandor()->Remove_unit(EG, attacked_unit);

				if (removed_success)
				{
					if (game_ptr->get_battle_mode() == INTERACTIVE)
						cout << attacked_unit->get_ID() << ",";
					if (attacked_unit->get_Health() == attacked_unit->get_originalHealth())
					{
						attacked_unit->set_Ta(game_ptr->get_Timestep());
					}

					drone1->Attack(attacked_unit);
					drone2->Attack(attacked_unit);

					attacked_EG.enqueue(attacked_unit);
				}
			}

			attacked_unit = nullptr;
		}
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "\b ]\n";
	}

}