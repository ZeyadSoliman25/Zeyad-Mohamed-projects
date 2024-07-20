#include "Car.h"
#include "MyList.h"  

#include <iostream>
#include <string>
using namespace std;

//Overloading operator == so that function MyList::getIndex works for Car objects 
bool operator ==(const Car& c1,const Car& c2)
{
	return (c1.price == c2.price && c1.year == c2.year);
}

int main()
{
	
	//Creating a list of Car using class MyList and operator overloading for operator ==
	cout<<"\nCreating a list of Car using class MyList and operator overloading for operator ==";
	Car C1(100000, 2011), C2(200000, 2012), C3(300000, 2013);

	MyList<Car> CList(10);
	CList.addItem(C3);
	CList.addItem(C1);
	CList.addItem(C2);
	
	cout << "\nPrinting CarList1 contents:" << endl;
	for (int i = 0; i < CList.getCount(); i++)	
		cout <<"Price= " << CList.getItem(i).price <<", year= "<<CList.getItem(i).year  << endl;

	double price;
	int year;
	cout<<"\nEnter a Car to search for:";
	cout<<"\nCar price:";
	cin>>price;
	cout<<"\nCar year:";
	cin>>year;
	Car X(price, year);
	int ind = CList.getIndex(X);
	if(ind < 0)
		cout<<"\nCar NOT found";
	else
		cout<<"\nCar found at index "<<ind;
	
	char dummy;
	cin>>dummy;

	return 0;
}
