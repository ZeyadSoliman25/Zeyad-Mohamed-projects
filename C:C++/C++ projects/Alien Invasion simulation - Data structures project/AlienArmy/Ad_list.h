#pragma once
#include <iostream>
#include "Ad.h"
#include "../DS/LinkedDeQueue.h"

using namespace std;

class Ad_list
{
	private:
		LinkedDeQueue<Ad *> Alien_drones;
		int count;

	public:
		/*Add new alien drone to front of the list*/
		bool Add_AD_front(Ad*& drone);

		/*Add new alien drone to rear of the list*/
		bool Add_AD_rear(Ad*& drone);

		/*Remove pair alien drones from the list*/
		bool Remove_AD(Ad*& drone1, Ad*& drone2);

		/*get the alien drone at the front of list*/
		bool Deploy_AD_front(Ad*& drone);

		/*get the alien drone at the rear of list*/
		bool Deploy_AD_rear(Ad*& drone);

		/*get the count of the alien drone*/
		int get_count(void);

		/*print the info of the list by printing the count, name of the list and the IDs*/
		void Print_info();

		//Default constructor to initialize count 
		Ad_list();
};

