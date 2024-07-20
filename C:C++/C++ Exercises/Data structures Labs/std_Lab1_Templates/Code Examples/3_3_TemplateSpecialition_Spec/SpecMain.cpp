#include "MyList.h"  

#include <iostream>
#include <string>
using namespace std;


int main()
{

	
	//Creating a list of char* (names) using class template specilaization
	cout<<"\nCreating a list of char* (names) using class template specilaization";
	
	char name1[30] = "Ahmed Emad";
	char name2[50] = "Safaa Mahmoud";
	char name3[20] = "Hani Farouk";
	char *res;
	
	MyList<char*> NamesList(5);
	NamesList.addItem(name3);
	NamesList.addItem(name1);
	NamesList.addItem(name2);
	cout << "\nPrinting NamesList contents:" << endl;
	for (int i = 0; i < NamesList.getCount(); i++)
		cout << NamesList.getItem(i) << endl;

	
	char name[100];
	cout<<"\nEnter a name to search for:";
	cin.getline(name, 100);
	int ind = NamesList.getIndex(name);
	if(ind < 0)
		cout<<endl<<name<<" NOT in the list";
	else
		cout<<endl<<name<<" found at index "<<ind;


	char dummy;
	cin>>dummy;	
	return 0;
}
