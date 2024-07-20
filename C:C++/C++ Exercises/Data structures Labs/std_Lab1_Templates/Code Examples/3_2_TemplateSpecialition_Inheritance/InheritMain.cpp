#include "CarList.h"
#include "MyList.h"  

#include <iostream>
#include <string>
using namespace std;


bool operator ==(const Car& c1,const Car& c2)
{
	return (c1.price == c2.price && c1.year == c2.year);
}

int main()
{
	
	//Creating a list of Car using class MyList
	cout<<"\nCreating a list of Car using class MyList (generic template)";
	Car C1(100000, 2011), C2(200000, 2012), C3(300000, 2013);

	MyList<Car> CList(10);
	CList.addItem(C3);
	CList.addItem(C1);
	CList.addItem(C2);
	
	cout << "\nPrinting CarList1 contents:" << endl;
	for (int i = 0; i < CList.getCount(); i++)	
		cout <<"Price= " << CList.getItem(i).price <<", year= "<<CList.getItem(i).year  << endl;


	
	//Creating a list of Car using derived class CarList
	cout<<"\nCreating a list of Car using derived class CarList";
	CarList CList2(10);
	CList2.addItem(C3);
	CList2.addItem(C1);
	CList2.addItem(C2);
	
	cout << "\nPrinting CarList2 contents:" << endl;
	cout << "Notice that CarList2 is sorted:" << endl;

	for (int i = 0; i < CList2.getCount(); i++)	
		cout <<"Price= " << CList2.getItem(i).price <<", year= "<<CList2.getItem(i).year  << endl;
	

	double price;
	int year;
	cout<<"\nEnter a Car to search for:";
	cout<<"\nCar price:";
	cin>>price;
	cout<<"\nCar year:";
	cin>>year;
	Car X(price, year);
	int ind = CList2.getIndex(X);
	if(ind < 0)
		cout<<"\nCar NOT found";
	else
		cout<<"\nCar found at index "<<ind;

	cout<<"\nGetting cheapest car";
	ind = CList2.GetCheapest();
	if(ind < 0)
		cout<<"\nCar NOT found";
	else
		cout<<"\nCheapest Car is at index "<<ind;

	
	char dummy;
	cin>>dummy;	
	return 0;
}
