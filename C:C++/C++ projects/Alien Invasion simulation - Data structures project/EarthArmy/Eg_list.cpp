#include "EG_list.h"


/*Add new earth gunner*/
bool Eg_list:: Add_EG(Eg*& gunner)
{
	bool insert_success = false;

	if (gunner)
	{
		count++;
		Earth_gunnery.enqueue(gunner, gunner->get_Overall_Power());
		insert_success = true;
	}
	return insert_success;
}

/*Remove earth gunner*/
bool Eg_list:: Remove_EG(Eg*& gunner)
{
	bool remove_success = false;
	if (!Earth_gunnery.isEmpty())
	{
		int overall_power;
		count--;
		remove_success = Earth_gunnery.dequeue(gunner, overall_power);
		gunner->set_Overall_Power(overall_power);
	}

	return remove_success;
}

/*Get the front gunner from the list*/
bool Eg_list :: Deploy_EG(Eg*& E_gunner)
{
	bool remove_success = false;

	if (!Earth_gunnery.isEmpty())
	{
		int overall_power;
		remove_success = Earth_gunnery.peek(E_gunner, overall_power);
		E_gunner->set_Overall_Power(overall_power);
	}

	return remove_success;
}

/*get the count the earth gunners*/
int Eg_list::get_count()
{
	return count;
}

/*print the info of the list by printing the count, name of the list and the IDs*/
void Eg_list:: Print_info()
{
	if (!Earth_gunnery.isEmpty())
	{
		priQueue<Eg*> Temp_queue = Earth_gunnery;
		Eg* temp_gunner;
		int overall_power;

		cout << count << " EG" << " [ ";

		while (!Temp_queue.isEmpty())
		{
			Temp_queue.dequeue(temp_gunner, overall_power);

			cout << temp_gunner->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " EG" << "[ ]" << endl;
	}
}

Eg_list::Eg_list()
{
	count = 0;
}