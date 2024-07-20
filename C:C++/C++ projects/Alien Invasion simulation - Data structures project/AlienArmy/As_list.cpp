#include "As_list.h"

bool As_list :: Add_AS(As* solider)
{
	count++;
	return Alien_soliders.enqueue(solider);
}

/*Remove alien solider from the list*/
bool As_list:: Remove_AS(As*& solider)
{
	if (count == 0)
		return false;

	count--;
	return Alien_soliders.dequeue(solider);
}

/*get the alien solider at the front of list*/
bool As_list::Deploy_AS(As*& solider)
{
	return Alien_soliders.peek(solider);
}

int As_list::get_count()
{
	return count;
}

void As_list::Print_info()
{
	LinkedQueue<As*> Temp_queue = Alien_soliders;
	As* temp_solider;

	cout << count << " AS [ ";

	while (!Temp_queue.isEmpty())
	{
		Temp_queue.dequeue(temp_solider);

		cout << temp_solider->get_ID() << ",";
	}

	cout << "\b ] \n";
}

As_list::As_list()
{
	count = 0;
}