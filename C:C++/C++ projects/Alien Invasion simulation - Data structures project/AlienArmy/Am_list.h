#pragma once
#include "Am.h"

#define MAX_SIZE_ 200

class Am_list
{
	private:
		Am* Alien_Monsters[MAX_SIZE_]; //Array of pointers to monsters
		int count;

	public:
		/*Add new alien monster*/
		bool Add_AM(Am*& monster);

		/*Remove earth gunner*/
		bool Remove_AM(Am*& monster);

		/*get the count of the alien monsters*/
		int get_count(void);

		/*print the info of the list by printing the count, name of the list and the IDs*/
		void Print_info();

		//default constructor to initialize count
		Am_list();
};

