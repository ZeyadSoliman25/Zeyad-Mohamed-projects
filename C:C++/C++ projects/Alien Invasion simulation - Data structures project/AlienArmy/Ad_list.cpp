#include "Ad_list.h"


/*Add new alien drone to front of the list*/
bool Ad_list::Add_AD_front(Ad*& drone)
{
	count++;
	return Alien_drones.enqueue_front(drone);
}

/*Add new alien drone to back of the list*/
bool Ad_list::Add_AD_rear(Ad*& drone)
{
	count++;
	return Alien_drones.enqueue_rear(drone);
}

/*Remove pair alien drones from the list*/
bool Ad_list::Remove_AD(Ad*& drone1, Ad*& drone2)
{
	if (count >= 2)
	{
		count -= 2;
		Alien_drones.dequeue_rear(drone1);
		Alien_drones.dequeue_front(drone2);
		return true;
	}
	else if (count == 1)
	{
		count--;
		drone2 = nullptr;
		return Alien_drones.dequeue_front(drone1);
	}
	else
	{
		return false;
	}
}

/*get the alien drone at the front of list*/
bool Ad_list::Deploy_AD_front(Ad*& drone)
{
	return Alien_drones.peek_front(drone);
}

/*get the alien drone at the back of list*/
bool Ad_list::Deploy_AD_rear(Ad*& drone)
{
	return Alien_drones.peek_rear(drone);
}

/*get the count of the alien drones*/
int Ad_list::get_count()
{
	return count;
}

/*print the info of the list by printing the count, name of the list and the IDs*/
void Ad_list::Print_info()
{
	if (!Alien_drones.isEmpty())
	{
		LinkedDeQueue<Ad*> Temp_queue = Alien_drones;
		Ad* temp_drone;

		cout << count << " AD" << " [ ";

		while (!Temp_queue.isEmpty())
		{
			Temp_queue.dequeue_rear(temp_drone);

			cout << temp_drone->get_ID() << ",";
		}

		cout << "\b ] \n";
	}
	else
	{
		cout << 0 << " AD" << "[ ]" << endl;
	}

}

Ad_list::Ad_list()
{
	count = 0;
}