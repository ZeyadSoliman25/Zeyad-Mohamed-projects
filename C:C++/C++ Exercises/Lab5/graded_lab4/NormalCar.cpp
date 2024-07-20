#include "NormalCar.h"

NormalCar::NormalCar(string name, string plate, int year_model) {
	setName(name);
	setplateNb(plate);
	set_yearModel(year_model);

	seatCount = 4;
	Price = 60;
}


void NormalCar::set_yearModel(int model) {
	if (model < 2000)
	{
		yearModel = 0;
	}
	else if (model > 2024)
	{
		yearModel = 2024;
	}
	else
	{
		yearModel = model;
	}
}


void NormalCar::setPrice(int p) {
	if (p <= -60)
	{
		Price = 60;
	}
	else
	{
		Price = p + 60;

		if (yearModel <= 2010)
		{
			Price = Price - Price * 0.025;
		}
	}
}


void NormalCar::printInfo(void) {
	UberRide::printInfo();
	cout << "Year model: " << yearModel << endl;
}
