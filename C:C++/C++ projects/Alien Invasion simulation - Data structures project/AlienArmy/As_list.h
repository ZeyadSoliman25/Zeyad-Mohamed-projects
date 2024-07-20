#pragma once
#pragma once
#include "As.h"
#include "../DS/LinkedQueue.h"


class As_list
{
private:
	LinkedQueue<As*> Alien_soliders;
	int count;

public:
	bool Add_AS(As* solider);

	bool Remove_AS(As*& solider);

	bool Deploy_AS(As*& solider);

	int get_count(void);

	void Print_info();

	As_list();
};

