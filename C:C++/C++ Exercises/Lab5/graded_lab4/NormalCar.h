#pragma once
#include <iostream>
#include "UberRide.h"

class NormalCar : public UberRide
{
	private:
		int yearModel;

	public:
		NormalCar(string, string, int);
		void set_yearModel(int);
		void setPrice(int);
		void printInfo(void);
};

