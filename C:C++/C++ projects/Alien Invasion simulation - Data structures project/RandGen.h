#pragma once
#include "AlienArmy.h"
#include "EarthArmy.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>


class Game;

class RandGen
{
	private:
		int Num;
		int ES_probability; 
		int ET_probability; 
		int EG_probability;
		int HU_probability;
		int AS_probability; 
		int AM_probability; 
		int AD_probability;
		int Probabability; 
		int Earth_health_limit_1; // First limit of the earth units health
		int Earth_health_limit_2; // Second limit of the earth units health
		int Earth_power_limit_1; // First limit of the earth units power
		int Earth_power_limit_2; // Second limit of the earth units power
		int Earth_Attack_Capacity_limit_1; // First limit of the earth units attack capacity
		int Earth_Attack_Capacity_limit_2; // Second limit of the earth units attack capacity
		int Alien_health_limit_1; // First limit of the alien units health
		int Alien_health_limit_2; // Second limit of the alien units health
		int Alien_power_limit_1; // First limit of the alien units power
		int Alien_power_limit_2; // Second limit of the alien units power
		int Alien_Attack_Capacity_limit_1; // First limit of the alien units attack capacity
		int Alien_Attack_Capacity_limit_2; // Second limit of the alien units attack capacity
		int EarthArmy_ID; // Current available ID to give to the next generated earth army unit (1-999)
		int AlienArmy_ID; // Current available ID to give to the next generation alien army unit (2000 - 2999)
		

	public:

		void set_Num(int num);

		void set_Prob(int prob);


		void set_Earth_army_prob(int es_prob, int et_prob, int eg_prob, int hu_prob);

		void set_Alien_army_prob(int as_prob, int am_prob, int ad_prob);


		void set_Earth_health_limits(int E_health_limit1, int E_health_limit2);

		void set_Earth_power_limits(int E_power_limit1, int E_power_limit2);

		void set_Earth_attack_capacity_limits(int E_Att_cap_limit1, int E_Att_cap_limit2);


		void set_Alien_health_limits(int A_health_limit1, int A_health_limit2);

		void set_Alien_power_limits(int A_power_limit1, int A_power_limit2);

		void set_Alien_Attack_capacity_limits(int A_Att_cap_limit1, int A_att_cap_limit2);

		void create_unit(Game*& game_ptr);

		int get_max_earth_health_limit(void);

		RandGen();
};


