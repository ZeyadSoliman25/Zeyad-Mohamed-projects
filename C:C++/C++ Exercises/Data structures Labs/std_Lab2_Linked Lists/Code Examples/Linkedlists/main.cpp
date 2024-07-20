#include "LinkedList.h"
#include <iostream>
using namespace std;

//Function prototypes 

///////////////////////////////////////////////////////////////////////

int main()
{
	LinkedList<int> L;	//create an object of class LinkedList
	int val;
	int value_printed; 

	cout<<"\nPlease enter int values to add to the list (-1 to stop):\n";
	cin>>val;
	while(val != -1)
	{
		L.InsertBeg(val);
		cin>>val;
	}
	L.PrintList();

	cout<<" \n ..............  Lab Requirements .............\n";
	cout<<"\n Check File LinkedList.h and write the required member functions";
	cout<<"\n Then test these functions by calling them from the main()";

	cout << "\nPlease enter index value to print from the list :\n";
	cin >> value_printed;
	L.PrintKth(value_printed);

	L.DeleteLast();

	L.PrintList();

	cout<<endl;
	return 0;
}


