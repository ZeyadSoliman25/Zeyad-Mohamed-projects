#include "Hu_list.h"


/*Add new heal unit to the list*/
bool Hu_list::Add_HU(Hu*& tank)
{
	count++;
	return Heal_units.push(tank);
}

/*Remove heal unit from the list*/
bool Hu_list::Remove_HU(Hu*& tank)
{
	if (count == 0)
		return false;

	count--;
	return Heal_units.pop(tank);
}

/*get the heal unit at the front of list*/
bool Hu_list::Deploy_HU(Hu*& tank)
{
	return Heal_units.peek(tank);
}

/*get the heal units count*/
int Hu_list::get_count()
{
	return count;
}

/*print the info of the list by printing the count, name of the list and the IDs*/
void Hu_list::Print_info()
{
	if (!Heal_units.isEmpty())
	{
		ArrayStack<Hu*> Temp_stack = Heal_units;
		Hu* temp_healer;

		cout << count << " HU" << " [ ";

		while (!Temp_stack.isEmpty())
		{
			Temp_stack.pop(temp_healer);

			cout << temp_healer->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " HU" << "[ ]" << endl;
	}

}

Hu_list::Hu_list()
{
	count = 0;
}