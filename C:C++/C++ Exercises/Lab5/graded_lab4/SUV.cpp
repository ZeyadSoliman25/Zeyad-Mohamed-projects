#include "SUV.h"

SUV::SUV(string name, string plate_num) {
	setName(name);
	setplateNb(plate_num);
	seatCount = 7;
	Price = 100;
}


void SUV:: setPrice(int p) {
	if (p <= -100)
	{
		Price = 100;
	}
	else
	{
		Price = p + 100;
	}
}


void SUV:: goTravel(void) {
	Price = Price + Price * 0.2;
}
