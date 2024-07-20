#include "Game.h"

using namespace std;

void Game:: LoadFromFile(string filename)
{
	ifstream file(filename); 
	string line = ""; // string used in getline() function
	string subline = ""; // to slice the line into sublines and converting it to integers 
	int params[21] = { 0 }; // array to hold the parameters
	int param_int = 0; // integer to hold the parameter converted from subline
	int param_num = 0; //index of the parameter 

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.empty())
			{
				continue;
			}

			for (int i = 0; i < line.length(); i++)
			{
				if ( (line[i] == ' ') || (line[i] == '-'))
				{
					param_int = stoi(subline);
					params[param_num] = param_int;
					subline = "";
					param_num++;
					continue;
				}
				subline += line[i];
			}
			param_int = stoi(subline);
			params[param_num] = param_int; 
			param_num++;
			subline = "";

		}

		generator.set_Num(params[0]);
		generator.set_Earth_army_prob(params[1], params[2], params[3], params[4]);
		generator.set_Alien_army_prob(params[5], params[6], params[7]);
		generator.set_Prob(params[8]);
		generator.set_Earth_power_limits(params[9], params[10]);
		generator.set_Earth_health_limits(params[11], params[12]);
		generator.set_Earth_attack_capacity_limits(params[13], params[14]);
		generator.set_Alien_power_limits(params[15], params[16]);
		generator.set_Alien_health_limits(params[17], params[18]);
		generator.set_Alien_Attack_capacity_limits(params[19], params[20]);

		damaged_units.set_max_earth_health_limit(params[12]); // to set the max health limit in the UML list to be used in the priority of adding soliders 

	}
}


void Game::GenerateOutputFile(string filename)
{
	ofstream output_file(filename);
	Unit* killed_unit = nullptr;
	float Es_destructed_precent = 0;
	float Et_destructed_precent = 0;
	float Eg_destructed_precent = 0;
	float As_destructed_precent = 0;
	float Am_destructed_precent = 0;
	float Ad_destructed_precent = 0;
	float total_Earth_units_destruct_precent = 0;
	float total_Alien_units_destruct_precent = 0;
	float Average_Df_Earth = 0;
	float Average_Db_Earth = 0;
	float Average_Dd_Earth = 0;
	float Average_Df_Alien = 0;
	float Average_Db_Alien = 0;
	float Average_Dd_Alien = 0;
	float healed_units_percentage = 0;
	int sum_destructed_Es = 0;
	int sum_destructed_Et = 0;
	int sum_destructed_Eg = 0;
	int sum_destructed_As = 0;
	int sum_destructed_Am = 0;
	int sum_destructed_Ad = 0;
	int sum_Df_Earth = 0;
	int sum_Db_Earth = 0;
	int sum_Dd_Earth = 0;
	int sum_Df_Alien = 0;
	int sum_Db_Alien = 0;
	int sum_Dd_Alien = 0;
	

	if (output_file.is_open())
	{
		output_file << "Td    ID    Tj    Df    Dd    Db" << endl;

		while (!Killed_List.isEmpty())
		{
			Killed_List.dequeue(killed_unit);
			int killed_unit_type = killed_unit->get_Type();

			if (killed_unit_type == ES)
			{
				sum_destructed_Es++;
				sum_Db_Earth += killed_unit->get_Db();
				sum_Df_Earth += killed_unit->get_Df();
				sum_Dd_Earth += killed_unit->get_Dd();
			}
			else if (killed_unit_type == ET)
			{
				sum_destructed_Et++;
				sum_Db_Earth += killed_unit->get_Db();
				sum_Df_Earth += killed_unit->get_Df();
				sum_Dd_Earth += killed_unit->get_Dd();
			}
			else if (killed_unit_type == EG)
			{
				sum_destructed_Eg++;
				sum_Db_Earth += killed_unit->get_Db();
				sum_Df_Earth += killed_unit->get_Df();
				sum_Dd_Earth += killed_unit->get_Dd();
			}
			else if (killed_unit_type == AS)
			{
				sum_destructed_As++;
				sum_Db_Alien += killed_unit->get_Db();
				sum_Df_Alien += killed_unit->get_Df();
				sum_Dd_Alien += killed_unit->get_Dd();
			}
			else if (killed_unit_type == AM)
			{
				sum_destructed_Am++;
				sum_Db_Alien += killed_unit->get_Db();
				sum_Df_Alien += killed_unit->get_Df();
				sum_Dd_Alien += killed_unit->get_Dd();
			}
			else if (killed_unit_type == AD)
			{
				sum_destructed_Ad++;
				sum_Db_Alien += killed_unit->get_Db();
				sum_Df_Alien += killed_unit->get_Df();
				sum_Dd_Alien += killed_unit->get_Dd();
			}

			output_file << killed_unit->get_Td() << "    " << killed_unit->get_ID() << "    " << killed_unit->get_Tj() << "    " << killed_unit->get_Df() << "    "<< killed_unit->get_Dd() << "    "<< killed_unit->get_Db() << endl;
			delete killed_unit;
		}

		Average_Db_Earth = (float)sum_Db_Earth / (sum_destructed_Eg + sum_destructed_Es + sum_destructed_Et);
		Average_Dd_Earth = (float)sum_Dd_Earth / (sum_destructed_Eg + sum_destructed_Es + sum_destructed_Et);
		Average_Df_Earth = (float)sum_Df_Earth / (sum_destructed_Eg + sum_destructed_Es + sum_destructed_Et);
		Average_Db_Alien = (float)sum_Db_Alien / (sum_destructed_As + sum_destructed_Am + sum_destructed_Ad);
		Average_Dd_Alien = (float)sum_Dd_Alien / (sum_destructed_As + sum_destructed_Am + sum_destructed_Ad);
		Average_Df_Alien = (float)sum_Df_Alien / (sum_destructed_As + sum_destructed_Am + sum_destructed_Ad);
		Eg_destructed_precent = (float)sum_destructed_Eg / this->get_Total_Eg();
		Et_destructed_precent = (float)sum_destructed_Et / this->get_Total_Et();
		Es_destructed_precent = (float)sum_destructed_Es / this->get_Total_Es();
		As_destructed_precent = (float)sum_destructed_As / this->get_Total_As();
		Am_destructed_precent = (float)sum_destructed_Am / this->get_Total_Am();
		Ad_destructed_precent = (float)sum_destructed_Ad / this->get_Total_Ad();
		total_Earth_units_destruct_precent = (float)(sum_destructed_Es + sum_destructed_Eg + sum_destructed_Et) / (Total_Eg + Total_Et + Total_Es);
		total_Alien_units_destruct_precent = (float)(sum_destructed_Ad + sum_destructed_Am + sum_destructed_As) / (Total_As + Total_Am + Total_Ad);

		if ((Total_Eg + Total_Et + Total_Es) == 0)
		{
			healed_units_percentage = 0;
		}
		else
		{
			healed_units_percentage = (float) healed_units_count / (Total_Eg + Total_Et + Total_Es);
		}

		output_file << "====================================" << endl;
		output_file << "Battle_result: ";
		if (battle_result == Earth_win)
		{
			output_file << "Earth army win" << endl;
		}
		else if (battle_result == Alien_win)
		{
			output_file << "Alien army win" << endl;
		}
		else
		{
			output_file << "Draw" << endl;
		}

		output_file << "====================================" << endl;
		output_file << "For Earth army:" << endl;
		output_file << "Total Es: " << Total_Es << endl;
		output_file << "Total Et: " << Total_Et << endl;
		output_file << "Total Eg: " << Total_Eg << endl;
		output_file << "Total healed units percentage: " << healed_units_percentage * 100 << " %" << endl;
		output_file << "percentage of destructed Es: " << Es_destructed_precent * 100<< " %" << endl;
		output_file << "percentage of destructed Et: " << Et_destructed_precent * 100<< " %" << endl;
		output_file << "percentage of destructed Eg: " << Eg_destructed_precent * 100<< " %" << endl;
		output_file << "percentage of total destructed units: " << total_Earth_units_destruct_precent * 100 << " %" << endl;
		output_file << "Average Df: " << Average_Df_Earth<< endl;
		output_file << "Average Dd: " << Average_Dd_Earth<< endl;
		output_file << "Average Db: " << Average_Db_Earth<< endl;
		output_file << "Df//Db: " << Average_Df_Earth / Average_Db_Earth << endl;
		output_file << "Dd/Db: " << Average_Dd_Earth / Average_Db_Earth  << endl;

		output_file << "====================================" << endl;
		output_file << "For Alien army:" << endl;
		output_file << "Total As: " << Total_As << endl;
		output_file << "Total Am: " << Total_Am << endl;
		output_file << "Total Ad: " << Total_Ad << endl;
		output_file << "percentage of destructed As: " << As_destructed_precent * 100 << " %" << endl;
		output_file << "percentage of destructed Am: " << Am_destructed_precent * 100 << " %" << endl;
		output_file << "percentage of destructed Ad: " << Ad_destructed_precent * 100 << " %" << endl;
		output_file << "percentage of total destructed units: " << total_Alien_units_destruct_precent * 100 << " %" << endl;
		output_file << "Average Df: " << Average_Df_Alien<< endl;
		output_file << "Average Dd: " << Average_Dd_Alien<< endl;
		output_file << "Average Db: " << Average_Db_Alien<< endl;
		output_file << "Df//Db: " << Average_Df_Alien / Average_Db_Alien<< endl;
		output_file << "Dd/Db: " << Average_Dd_Alien / Average_Db_Alien<< endl;
	}

}


EarthArmy* Game:: get_EarthCommandor(void)
{
	return &EarthCommandor;
}

AlienArmy* Game:: get_AlienCommandor(void)
{
	return &AlienCommandor;
}

RandGen* Game:: get_generator(void)
{
	return &generator;
}

Hu_list* Game::get_Healers(void)
{
	return &healers;
}

Uml_list* Game::get_damaged_units(void)
{
	return &damaged_units;
}

void Game::heal_damaged_Earth_units(void)
{
	while ((healers.get_count() > 0) && (damaged_units.get_count_damaged_soliders() + damaged_units.get_count_damaged_tanks() > 0))
	{
		Hu* healer = nullptr;
		bool removed_success = healers.Remove_HU(healer);
		
		if (removed_success)
		{
			int heal_capacity = healer->get_Attack_capacity();
			int temp_heal_capacity = heal_capacity;

			for (int i = 0; i < heal_capacity; i++)
			{
				Es* damaged_solider = nullptr;
				bool solider_damaged_removed = damaged_units.remove_solider(damaged_solider);

				if (solider_damaged_removed)
				{
					if ((damaged_solider->get_joined_UML() + 10) >= this->get_Timestep())
					{
						Unit* killed_unit = damaged_solider;
						killed_unit->set_Td(this->get_Timestep());
						this->Add_to_killed_list(killed_unit);
					}
					else
					{
						Et* tank = nullptr;
						healer->Heal(damaged_solider, tank);
						healed_units_count++;
						temp_heal_capacity--;


						if (damaged_solider->get_Health() <= 0.2 * damaged_solider->get_originalHealth())
						{
							damaged_units.Add_Damaged_solider(damaged_solider, this);
						}
						else
						{
							Eg* gunner = nullptr;
							EarthCommandor.Add_unit(ES, damaged_solider, tank, gunner);
						}
					}
				}
				else
				{
					break;
				}

			}

			if (temp_heal_capacity > 0)
			{
				for (int i = 0; i < temp_heal_capacity; i++)
				{
					Et* damaged_tank = nullptr;
					bool tank_damaged_removed = damaged_units.remove_tank(damaged_tank);

					if (tank_damaged_removed)
					{
						if ((damaged_tank->get_joined_UML() + 10) > this->get_Timestep())
						{
							Unit* killed_unit = damaged_tank;
							killed_unit->set_Td(this->get_Timestep());
							this->Add_to_killed_list(killed_unit);
						}
						else
						{
							Es* solider = nullptr;
							healer->Heal(solider, damaged_tank);
							healed_units_count++;

							if (damaged_tank->get_Health() <= 0.2 * damaged_tank->get_originalHealth())
							{
								damaged_units.Add_Damaged_Tank(damaged_tank, this);
							}
							else
							{
								Eg* gunner = nullptr;
								EarthCommandor.Add_unit(ET, solider, damaged_tank, gunner);
							}
						}

					}
					else
					{
						break;
					}
				}
			}
		}
	}

}

bool Game::Add_to_killed_list(Unit*& killed_unit)
{
	if (!killed_unit)
		return false;

	killed_units_count++ ;
	return Killed_List.enqueue(killed_unit);
}

void Game::Check_killed_UML(void)
{
	while ((damaged_units.get_count_damaged_soliders() + damaged_units.get_count_damaged_tanks()) > 0)
	{
		Es* solider = nullptr;
		bool solider_removed_success = damaged_units.remove_solider(solider);

		if (solider_removed_success)
		{
			if (solider->get_joined_UML() + 10 >= this->get_Timestep())
			{
				Unit* killed_unit = solider;
				killed_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(killed_unit);
			}
			else
			{
				damaged_units.Add_Damaged_solider(solider, this);
			}
		}

		Et* tank = nullptr;
		bool tank_removed_success = damaged_units.remove_tank(tank);

		if (tank_removed_success)
		{
			if (tank->get_joined_UML() + 10 >= this->get_Timestep())
			{
				Unit* killed_unit = tank;
				killed_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(killed_unit);
			}
			else
			{
				damaged_units.Add_Damaged_Tank(tank, this);
			}
		}
	}
}

void Game:: Print_Killed_list(void)
{
	LinkedQueue<Unit*> temp_list = Killed_List;
	Unit* killed_unit;

	cout << "\n============== Killed/Destructed Units ==============" << endl;

	if (killed_units_count != 0)
	{
		cout << killed_units_count << " units [ ";

		while (temp_list.dequeue(killed_unit))
		{
			cout << killed_unit->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << killed_units_count << " units [ ] " << endl;
	}
}

bool Game::Add_to_heal_list(Hu*& heal_unit)
{
	return healers.Add_HU(heal_unit);
}

bool Game::Remove_heal_unit(Hu*& heal_unit)
{
	return healers.Remove_HU(heal_unit);
}

void Game::Print_heal_list(void)
{
	healers.Print_info();
}

void Game::Print_Uml_list(void)
{
	damaged_units.Print_Uml_list();
}

void Game::set_Timestep(int time)
{
	Timestep = time;
}

int Game::get_Timestep(void)
{
	return Timestep;
}


void Game::Armies_Attack(void)
{
	LinkedQueue<Unit*> attacked_ES;
	ArrayStack<Unit*> attacked_ET;
	LinkedQueue<Unit*> attacked_EG;
	LinkedQueue<Unit*> attacked_AS;
	LinkedQueue<Unit*> attacked_AM;
	LinkedQueue<Unit*> attacked_AD;
	
	Unit* temp_unit = nullptr;
	Unit* temp_unit2 = nullptr;

	if (battle_mode == INTERACTIVE)
	{
		this->Print_armies();

		cout << "\n============== Units Fighting at current timestep ==============" << endl;
	}


	EarthCommandor.Attack(this, attacked_AS, attacked_AM, attacked_AD);

	while (AlienCommandor.get_units_count(AS) > 0)
	{
		bool removed_success = AlienCommandor.Remove_unit(AS, temp_unit, temp_unit2);
		if (removed_success)
			attacked_AS.enqueue(temp_unit);
	}

	while (!attacked_AS.isEmpty())
	{
		bool removed_success = attacked_AS.dequeue(temp_unit);
		if (removed_success)
		{
			if (temp_unit->get_Health() <= 0)
			{
				temp_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(temp_unit);
			}
			else
			{
				As* new_solider = new As(temp_unit);
				Am* temp_monster = nullptr;
				Ad* temp_drone = nullptr;

				AlienCommandor.Add_unit(AS, new_solider, temp_monster, temp_drone);
			}

		}
	}

	while (!attacked_AM.isEmpty())
	{
		bool removed_success = attacked_AM.dequeue(temp_unit);

		if (removed_success)
		{
			if (temp_unit->get_Health() <= 0)
			{
				temp_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(temp_unit);
			}
			else
			{
				Am* new_monster = new Am(temp_unit);
				As* temp_solider = nullptr;
				Ad* temp_drone = nullptr;

				AlienCommandor.Add_unit(AM, temp_solider, new_monster, temp_drone);
			}
		}
	}

	while (!attacked_AD.isEmpty())
	{
		bool removed_success = attacked_AD.dequeue(temp_unit);

		if (removed_success)
		{
			if (temp_unit->get_Health() <= 0)
			{
				temp_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(temp_unit);
			}
			else
			{
				Ad* new_drone = new Ad(temp_unit);
				As* temp_solider = nullptr;
				Am* temp_monster = nullptr;

				AlienCommandor.Add_unit(AD, temp_solider, temp_monster, new_drone);
			}
		}
	}

	AlienCommandor.Attack(this, attacked_ES, attacked_ET, attacked_EG);

	while (EarthCommandor.get_units_count(ES) > 0)
	{
		bool removed_success = EarthCommandor.Remove_unit(ES, temp_unit);
		if (removed_success)
			attacked_ES.enqueue(temp_unit);
	}

	while (!attacked_ES.isEmpty())
	{
		bool removed_success = attacked_ES.dequeue(temp_unit);

		if (removed_success)
		{
			if (temp_unit->get_Health() <= 0)
			{
				temp_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(temp_unit);
			}
			else if (temp_unit->get_Health() <= 0.2 * temp_unit->get_originalHealth())
			{
				Es* damaged_solider = new Es(temp_unit);
				damaged_solider->set_joined_UML(this->get_Timestep());
				damaged_units.Add_Damaged_solider(damaged_solider, this);
			}
			else
			{
				Es* new_solider = new Es(temp_unit);
				Eg* temp_gunner = nullptr;
				Et* temp_tank = nullptr;

				EarthCommandor.Add_unit(ES, new_solider, temp_tank, temp_gunner);
			}
		}

		temp_unit = nullptr;
	}

	while (EarthCommandor.get_units_count(ET) > 0)
	{
		bool removed_success = EarthCommandor.Remove_unit(ET, temp_unit);

		if (removed_success)
			attacked_ET.push(temp_unit);
	}

	while (!attacked_ET.isEmpty())
	{
		bool removed_success = attacked_ET.pop(temp_unit);

		if (removed_success)
		{
			if (temp_unit->get_Health() <= 0)
			{
				temp_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(temp_unit);
			}
			else if (temp_unit->get_Health() <= 0.2 * temp_unit->get_originalHealth())
			{
				Et* damaged_tank = new Et(temp_unit);
				damaged_tank->set_joined_UML(this->get_Timestep());
				damaged_units.Add_Damaged_Tank(damaged_tank, this);
			}
			else
			{
				Et* new_tank = new Et(temp_unit);
				Es* temp_solider = nullptr;
				Eg* temp_gunner = nullptr;

				EarthCommandor.Add_unit(ET, temp_solider, new_tank, temp_gunner);
			}
		}
	}

	while (!attacked_EG.isEmpty())
	{
		bool removed_sucess = attacked_EG.dequeue(temp_unit);

		if (removed_sucess)
		{
			if (temp_unit->get_Health() <= 0)
			{
				temp_unit->set_Td(this->get_Timestep());
				this->Add_to_killed_list(temp_unit);
			}
			else
			{
				Eg* new_gunner = new Eg(temp_unit);
				Et* temp_tank = nullptr;
				Es* temp_solider = nullptr;

				new_gunner->set_Overall_Power((new_gunner->get_Power() + new_gunner->get_Health()) / 2);

				EarthCommandor.Add_unit(EG, temp_solider, temp_tank, new_gunner);
			}
		}
	}
	
}

void Game::Print_armies(void)
{
	cout << "============== Earth Army Alive Units ==============" << endl;
	EarthCommandor.Print_Earth_army();
	Print_heal_list();
	Print_Uml_list();
	

	cout << "============== Alien Army Alive Units ==============" << endl;
	AlienCommandor.Print_Alien_army();
}

void Game::set_Total_Es(int num_Es)
{
	Total_Es = num_Es;
}

void Game::set_Total_Et(int num_Et)
{
	Total_Et = num_Et;
}

void Game::set_Total_Eg(int num_Eg)
{
	Total_Eg = num_Eg;
}

void Game::set_Total_As(int num_As)
{
	Total_As = num_As;
}

void Game::set_Total_Am(int num_Am)
{
	Total_Am = num_Am;
}

void Game::set_Total_Ad(int num_Ad)
{
	Total_Ad = num_Ad;
}

void Game::set_battle_mode(int mode)
{
	battle_mode = mode;
}

int Game::get_Total_Es(void)
{
	return Total_Es;
}

int Game::get_Total_Et(void)
{
	return Total_Et;
}

int Game::get_Total_Eg(void)
{
	return Total_Eg;
}

int Game::get_Total_As(void)
{
	return Total_As;
}

int Game::get_Total_Am(void)
{
	return Total_Am;
}

int Game::get_Total_Ad(void)
{
	return Total_Ad;
}

int Game::get_battle_mode(void)
{
	return battle_mode;
}

void Game::check_winner(void)
{
	if ( (EarthCommandor.get_units_count(ES) + EarthCommandor.get_units_count(ET) + EarthCommandor.get_units_count(EG)) == 0)
	{
		battle_result = Alien_win;
	}
	else if ((AlienCommandor.get_units_count(AS) + AlienCommandor.get_units_count(AM) + AlienCommandor.get_units_count(AD)) == 0)
	{
		battle_result = Earth_win;
	}
	else
	{
		battle_result = Draw;
	}
}

int Game::get_battle_result(void)
{
	return battle_result;
}

Game::Game()
{
	Timestep = 1;
	Total_Ad = 0;
	Total_Am = 0;
	Total_As = 0;
	Total_Eg = 0;
	Total_Es = 0;
	Total_Et = 0;
	battle_result = Draw;
	healed_units_count = 0;
	killed_units_count = 0;
	battle_mode = 0;
}

Game::~Game()
{
	Unit* removed_unit;
	Unit* removed_unit2;

	while (EarthCommandor.Remove_unit(ES, removed_unit))
	{
		delete removed_unit;
	}

	while (EarthCommandor.Remove_unit(ET, removed_unit))
	{
		delete removed_unit;
	}

	while (EarthCommandor.Remove_unit(EG, removed_unit))
	{
		delete removed_unit;
	}

	while (AlienCommandor.Remove_unit(AS, removed_unit, removed_unit2))
	{
		delete removed_unit;
	}

	while (AlienCommandor.Remove_unit(AM, removed_unit, removed_unit2))
	{
		delete removed_unit;
	}
	
	while (AlienCommandor.Remove_unit(AD, removed_unit, removed_unit2))
	{
		if (removed_unit)
		{
			delete removed_unit;
		}

		if (removed_unit2)
		{
			delete removed_unit2;
		}
	}
}