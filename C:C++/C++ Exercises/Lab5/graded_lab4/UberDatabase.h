#pragma once
#include <iostream>
#include "UberRide.h"

#define max_uber_rides	100
class UberDatabase
{
	private:
		UberRide * UberRideArr[max_uber_rides] = {NULL};
		int count = 0;

	public:
		void addUberRide(UberRide*);
		void printData(void);
		UberRide* updateUberRide(int i);
};

