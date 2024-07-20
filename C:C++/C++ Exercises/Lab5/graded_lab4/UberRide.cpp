#include "UberRide.h"

void UberRide:: setName(string name){
	bool is_name = true;

	for (int i = 0; i < name.length(); i++) 
	{
		if ((name[i] >= '0') && (name[i] <= '9'))
		{
			is_name = false;
		}
	}

	if (is_name)
	{
		Name = name;
	}
	else
	{
		Name = "N.A";
	}
}


bool UberRide::takeNewPassenger(void) {
	if (seatCount != 0)
	{
		seatCount--;
		return true;
	}
	else
	{
		return false;
	}
}


int UberRide :: getPrice(void) {
	return Price;
}


void UberRide::setplateNb(string plate_nb) {
	bool is_plate_nb = true;

	if ( (plate_nb.length() < 6) || (plateNb.length() > 6)) {
		plateNb = " ";
		return;
	}

	for (int i = 0; i < plate_nb.length(); i++) {
		if (i < 3)
		{
			if ((plate_nb[i] >= '0') && (plate_nb[i] <= '9'))
			{
				is_plate_nb = false;
			}
		}
		else
		{
			if (! ( (plate_nb[i] >= '0') && (plate_nb[i] <= '9') ) )
			{
				is_plate_nb = false;
			}
		}
	}


	if (is_plate_nb)
	{
		plateNb = plate_nb;
	}
	else
	{
		plateNb = " ";
	}
}


void UberRide::printInfo(void) {
	cout << "Info: \n";
	cout << "Name: "<< Name << endl;
	cout << "seat-count: " << seatCount << endl;
	cout << "Plate number: " << plateNb << endl;
	cout << "Price: " << Price << endl;
}
