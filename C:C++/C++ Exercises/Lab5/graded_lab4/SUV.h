#pragma once
#include <iostream>
#include "UberRide.h"
class SUV : public UberRide 
{
	public:
		SUV(string, string);
		void setPrice(int);
		void goTravel(void);
};

