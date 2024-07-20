#include "ES_list.h"


/*Add new earth solider to the list*/
bool Es_list:: Add_ES(Es*& solider)
{
	count++;
	return Earth_soliders.enqueue(solider);
}

/*Remove earth solider from the list*/
bool Es_list :: Remove_ES(Es*& solider)
{
	if (count == 0)
		return false;

	count--;
	return Earth_soliders.dequeue(solider);
}

/*get the earth solider at the front of list*/
bool Es_list :: Deploy_ES(Es*& solider)
{
	return Earth_soliders.peek(solider);
}

/*get the earth soliders count*/
int Es_list::get_count()
{
	return count;
}

/*print the info of the list by printing the count, name of the list and the IDs*/
void Es_list :: Print_info()
{
	if (!Earth_soliders.isEmpty())
	{
		LinkedQueue<Es*> Temp_queue = Earth_soliders;
		Es* temp_solider;

		cout << count << " ES" << " [ ";

		while (!Temp_queue.isEmpty())
		{
			Temp_queue.dequeue(temp_solider);

			cout << temp_solider->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " ES" << "[ ]" << endl;
	}

}

Es_list::Es_list()
{
	count = 0;
}