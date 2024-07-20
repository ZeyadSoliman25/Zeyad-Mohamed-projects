#include "RandGen.h"
#include "Game.h"


void RandGen:: set_Num(int num)
{
	Num = num;
}


void RandGen:: set_Prob(int prob)
{
	Probabability = prob;
}


void RandGen:: set_Earth_army_prob(int es_prob, int et_prob, int eg_prob, int hu_prob)
{
	ES_probability = es_prob;
	ET_probability = et_prob;
	EG_probability = eg_prob;
	HU_probability = hu_prob;
}


void RandGen:: set_Alien_army_prob(int as_prob, int am_prob, int ad_prob)
{
	AS_probability = as_prob;
	AM_probability = am_prob;
	AD_probability = ad_prob;
}


void RandGen:: set_Earth_health_limits(int E_health_limit1, int E_health_limit2)
{
	Earth_health_limit_1 = E_health_limit1;
	Earth_health_limit_2 = E_health_limit2;
}


void RandGen:: set_Earth_power_limits(int E_power_limit1, int E_power_limit2)
{
	Earth_power_limit_1 = E_power_limit1;
	Earth_power_limit_2 = E_power_limit2;
}


void RandGen:: set_Earth_attack_capacity_limits(int E_Att_cap_limit1, int E_Att_cap_limit2)
{
	Earth_Attack_Capacity_limit_1 = E_Att_cap_limit1;
	Earth_Attack_Capacity_limit_2 = E_Att_cap_limit2;
}


void RandGen:: set_Alien_health_limits(int A_health_limit1, int A_health_limit2)
{
	Alien_health_limit_1 = A_health_limit1;
	Alien_health_limit_2 = A_health_limit2;
}


void RandGen:: set_Alien_power_limits(int A_power_limit1, int A_power_limit2)
{
	Alien_power_limit_1 = A_power_limit1;
	Alien_power_limit_2 = A_power_limit2;
}


void RandGen:: set_Alien_Attack_capacity_limits(int A_Att_cap_limit1, int A_att_cap_limit2)
{
	Alien_Attack_Capacity_limit_1 = A_Att_cap_limit1;
	Alien_Attack_Capacity_limit_2 = A_att_cap_limit2;
}

void RandGen::create_unit(Game*& game_ptr)
{
	EarthArmy* EarthCommandor = game_ptr->get_EarthCommandor();
	AlienArmy* AlienCommandor = game_ptr->get_AlienCommandor();

	srand(time(NULL)); 
	int prob_A = rand() % 100 + 1; 
	int current_timestep = game_ptr->get_Timestep();


	if (prob_A <= Probabability)
	{
		int prob_B = 0; 
		int unit_health = 0; 
		int unit_power = 0; 
		int unit_attack_cap = 0; 

		/*Loop to generate Earth units*/
		for (int i = 1; i <= Num; i++)
		{
			prob_B = rand() % 100 + 1; 
			unit_health = rand() % Earth_health_limit_2 + Earth_health_limit_1;
			unit_power = rand() % Earth_power_limit_2 + Earth_power_limit_1;
			unit_attack_cap = rand() % Earth_Attack_Capacity_limit_2 + Earth_Attack_Capacity_limit_1;

			if (prob_B <= ES_probability)
			{
				Es* solider = new Es(EarthArmy_ID, ES, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				Et* tank = nullptr;
				Eg* gunner = nullptr;
				EarthCommandor->Add_unit(ES, solider, tank, gunner);
				game_ptr->set_Total_Es(game_ptr->get_Total_Es() + 1);
			}
			else if (prob_B <= (ES_probability+ET_probability) )
			{
				Et* tank = new Et(EarthArmy_ID, ET, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				Es* solider = nullptr;
				Eg* gunner = nullptr;
				EarthCommandor->Add_unit(ET, solider, tank, gunner);
				game_ptr->set_Total_Et(game_ptr->get_Total_Et() + 1);
			}
			else if (prob_B <= (ES_probability+ET_probability+EG_probability) )
			{
				Eg* gunner = new Eg(EarthArmy_ID, EG, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				Et* tank = nullptr;
				Es* solider = nullptr;
				EarthCommandor->Add_unit(EG, solider, tank, gunner);
				game_ptr->set_Total_Eg(game_ptr->get_Total_Eg() + 1);
			}
			else
			{
				Hu* healer = new Hu(EarthArmy_ID, HU, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				game_ptr->Add_to_heal_list(healer);
			}

			if (EarthArmy_ID < 2000)
			{
				EarthArmy_ID++;
			}
		}

		/*Loop to generate Alien units*/
		for (int i = 1; i <= Num; i++)
		{
			prob_B = rand() % 100 + 1;
			unit_health = rand() % Alien_health_limit_2 + Alien_health_limit_1;
			unit_power = rand() % Alien_power_limit_2 + Alien_power_limit_1;
			unit_attack_cap = rand() % Alien_Attack_Capacity_limit_2 + Alien_Attack_Capacity_limit_1;

			if (prob_B <= AS_probability)
			{
				As* solider = new As(AlienArmy_ID, AS, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				Am* monster = nullptr;
				Ad* drone = nullptr;
				AlienCommandor->Add_unit(AS,solider, monster, drone);
				game_ptr->set_Total_As(game_ptr->get_Total_As() + 1);
			}
			else if (prob_B <= (AS_probability + AM_probability))
			{
				Am* monster = new Am(AlienArmy_ID, AM, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				As* solider = nullptr;
				Ad* drone = nullptr;
				AlienCommandor->Add_unit(AM,solider, monster, drone);
				game_ptr->set_Total_Am(game_ptr->get_Total_Am() + 1);
			}
			else
			{
				Ad* drone = new Ad(AlienArmy_ID, AD, current_timestep, unit_health, unit_health, unit_power, unit_attack_cap);
				As* solider = nullptr;
				Am* monster = nullptr;
				AlienCommandor->Add_unit(AD,solider,monster, drone);
				game_ptr->set_Total_Ad(game_ptr->get_Total_Ad() + 1);
			}

			if (AlienArmy_ID < 4000)
			{
				AlienArmy_ID++;
			}
		}
	}
}

int RandGen::get_max_earth_health_limit(void)
{
	return Earth_health_limit_2;
}

RandGen::RandGen()
{

	EarthArmy_ID = 1;
	AlienArmy_ID = 2000;
	Num = 0; 
	ES_probability = 0; 
	ET_probability = 0; 
	EG_probability = 0; 
	HU_probability = 0;
	AS_probability = 0; 
	AM_probability = 0; 
	AD_probability = 0; 
	Probabability = 0; 
	Earth_health_limit_1 = 0; 
	Earth_health_limit_2 = 0; 
	Earth_power_limit_1 = 0; 
	Earth_power_limit_2 = 0; 
	Earth_Attack_Capacity_limit_1 = 0; 
	Earth_Attack_Capacity_limit_2 = 0; 
	Alien_health_limit_1 = 0;;
	Alien_health_limit_2 = 0; 
	Alien_power_limit_1 = 0; 
	Alien_power_limit_2 = 0; 
	Alien_Attack_Capacity_limit_1 = 0; 
	Alien_Attack_Capacity_limit_2 = 0; 
}