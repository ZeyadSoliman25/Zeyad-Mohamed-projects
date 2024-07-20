#include <iostream>
#include "NormalCar.h"
#include "SUV.h"
#include "UberDatabase.h"
#include "UberRide.h"

void main()
{
	UberDatabase db; 
	NormalCar normal1("Ahmed", "abc123", 2023);
	SUV suv1("Osman", "fde133");
	NormalCar normal2("Khaled", "mmm444", 2009);
	NormalCar normal3("Amir", "aam879", 2017);
	SUV suv2("Farid", "bbw896");

	SUV suv3("Khaled", "jk254");


	NormalCar* normal_ptr_1, * normal_ptr_2, * normal_ptr_3;
	SUV* suv_ptr_1, * suv_ptr_2;

	normal_ptr_1 = &normal1;
	normal_ptr_2 = &normal2;
	normal_ptr_3 = &normal3;
	suv_ptr_1 = &suv1;
	suv_ptr_2 = &suv2;


	db.addUberRide(normal_ptr_1);
	db.addUberRide(suv_ptr_1);
	db.addUberRide(normal_ptr_2);
	db.addUberRide(normal_ptr_3);
	db.addUberRide(suv_ptr_2);

	for (int i = 0; i < 5; i++) {
		UberRide* ptr = db.updateUberRide(i);
		ptr->setPrice(i * 10);
	}

	db.printData();

	suv_ptr_2->goTravel();
	cout << "\nnew price: " << suv_ptr_2->getPrice() << endl;

	NormalCar* ptr_normal = (NormalCar*) db.updateUberRide(2);
	((UberRide*) ptr_normal)->printInfo();
}