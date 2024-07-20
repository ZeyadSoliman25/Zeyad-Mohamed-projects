#pragma once
#include <iostream>
#include "Et.h"
#include "../DS/ArrayStack.h"

using namespace std;

class Et_list
{
	private:
		ArrayStack <Et*> Earth_tanks;
		int count;

	public:
		/*Add new earth tank to the list*/
		bool Add_ET(Et*& tank);

		/*Remove earth tank from the list*/
		bool Remove_ET(Et*& tank);

		/*get the earth tank at the front of list*/
		bool Deploy_ET(Et*& tank);

		/*get the earth tanks count*/
		int get_count(void);

		/*print the info of the list by printing the count, name of the list and the IDs*/
		void Print_info();

		//default constructor to initialize count;
		Et_list();
};

