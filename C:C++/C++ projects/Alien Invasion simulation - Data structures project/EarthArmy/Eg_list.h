#pragma once
#include <iostream>
#include "Eg.h"
#include "../DS/priQueue.h"

using namespace std;

class Eg_list
{
	private:
		priQueue<Eg*> Earth_gunnery;
		int count ;

	public:

		/*Add new earth gunner*/
		bool Add_EG(Eg*& gunner);

		/*Remove earth gunner*/
		bool Remove_EG(Eg*& gunner);

		/*Get the front gunner from the list*/
		bool Deploy_EG(Eg*& E_gunner);

		/*get the count of the earth gunners*/
		int get_count(void);

		/*print the info of the list by printing the count, name of the list and the IDs*/
		void Print_info();

		//default constructor to initialize count
		Eg_list();
};
