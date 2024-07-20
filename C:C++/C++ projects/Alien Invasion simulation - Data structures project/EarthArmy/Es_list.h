#pragma once
#include <iostream>
#include "Es.h"
#include "../DS/LinkedQueue.h"

using namespace std;

class Es_list 
{
	private:
		LinkedQueue<Es *> Earth_soliders;
		int count;

	public:

		/*Add new earth solider to the list*/
		bool Add_ES(Es*& solider);

		/*Remove earth solider from the list*/
		bool Remove_ES(Es*& solider);

		/*get the earth solider at the front of list*/
		bool Deploy_ES(Es*& solider);

		/*get the count of the earth soliders*/
		int get_count(void);

		/*print the info of the list by printing the count, name of the list and the IDs*/
		void Print_info();

		//Default constructor to initialize count 
		Es_list();
};
