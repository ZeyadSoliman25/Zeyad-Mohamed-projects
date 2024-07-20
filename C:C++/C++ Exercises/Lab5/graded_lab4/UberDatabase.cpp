#include "UberDatabase.h"


void UberDatabase::addUberRide(UberRide* captain) {
	if (count != (max_uber_rides -1))
	{
		UberRideArr[count] = captain;
		count++;
	}
	else
	{
		cout << "Can't add captain\n";
	}
}


void UberDatabase::printData(void) {
	for (int i = 0; i < count; i++) {
		UberRideArr[i]->printInfo();
	}
}

UberRide* UberDatabase::updateUberRide(int i) {
	if (i <= count)
	{
		return UberRideArr[i];
	}
	else
	{
		cout << "Cannot find captain\n";
	}
	return NULL;
}