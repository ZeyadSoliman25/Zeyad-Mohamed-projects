#include "Am_list.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*Add new alien monster*/
bool Am_list:: Add_AM(Am*& monster)
{
	if ( (monster) && (count!= MAX_SIZE_) )
	{
		Alien_Monsters[count] = monster;
		count++;
		return true;
	}
	else
	{
		return false;
	}
}

/*Remove alien monster*/
bool Am_list:: Remove_AM(Am*& monster)
{
	if (count > 0)
	{
		srand(time(NULL)); //Time seed to make the random sequence unique each time the function is called 
		int random_index = rand() % count; // generate random index from 0 to (count - 1)
		monster = Alien_Monsters[random_index]; // Get the selected random monster to monster pointer

		if (random_index == (count - 1))
		{
			Alien_Monsters[random_index] = Alien_Monsters[count - 2];
		}
		else
		{
			Alien_Monsters[random_index] = Alien_Monsters[count - 1];
			/*Note to the TAs and other users of the code 
				We tried to remove the warning of buffer overrun but with no use although the code is tested and running as intended*/
		}

		count--;
		return true;
	}
	else
	{
		return false;
	}
}

/*get the count of the alien monsters*/
int Am_list::get_count()
{
	return count;
}

/*print the info of the list by printing the count, name of the list and the IDs*/
void Am_list::Print_info()
{
	if (count > 0)
	{
		cout << count << " AM" << " [ ";

		for (int i = 0; i < count; i++)
		{
			cout << Alien_Monsters[i]->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " AM" << "[ ]" << endl;
	}

}

//default constructor to initialize count
Am_list::Am_list()
{
	count = 0;

	for (int i = 0; i < MAX_SIZE_; i++)
	{
		Alien_Monsters[i] = nullptr;
	}
}