#pragma once
#include <iostream>
#include "../DS/ArrayStack.h"
#include "Hu.h"

using namespace std;

class Hu_list
{
	private:
		ArrayStack <Hu*> Heal_units;
		int count;

	public:
		/*Add new heal unit to the list*/
		bool Add_HU(Hu*& healer);

		/*Remove Heal unit from the list*/
		bool Remove_HU(Hu*& healer);

		/*get the Heal unit at the front of list*/
		bool Deploy_HU(Hu*& healer);

		/*get the Heal units count*/
		int get_count(void);

		/*print the info of the list by printing the count, name of the list and the IDs*/
		void Print_info();

		//default constructor to initialize count;
		Hu_list();

};

