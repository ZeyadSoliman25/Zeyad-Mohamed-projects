#include "ET_list.h"


/*Add new earth tank to the list*/
bool Et_list:: Add_ET(Et*& tank)
{
	count++;
	return Earth_tanks.push(tank);
}

/*Remove earth tank from the list*/
bool Et_list :: Remove_ET(Et*& tank)
{
	if (count == 0)
		return false;

	count--;
	return Earth_tanks.pop(tank);
}

/*get the earth tank at the front of list*/
bool Et_list:: Deploy_ET(Et*& tank)
{
	return Earth_tanks.peek(tank);
}

/*get the earth tanks count*/
int Et_list::get_count()
{
	return count;
}

/*print the info of the list by printing the count, name of the list and the IDs*/
void Et_list::Print_info()
{
	if (!Earth_tanks.isEmpty())
	{
		ArrayStack<Et*> Temp_stack = Earth_tanks;
		Et* temp_tank;

		cout << count << " ET" << " [ ";

		while (!Temp_stack.isEmpty())
		{
			Temp_stack.pop(temp_tank);

			cout << temp_tank->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " ET" << "[ ]" << endl;
	}

}

Et_list::Et_list()
{
	count = 0;
}