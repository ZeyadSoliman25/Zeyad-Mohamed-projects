
#include "MyList.h"  

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, n;

	n=7;
	
	//instantiate a version of MyList for int Type
	MyList<int> V1(n);	

	for (i = 0; i<n; i++)
	{
		V1.addItem(i * 5);
	}
	cout << "\nPrinting V1 contents:" << endl;
	for (i = 0; i < V1.getCount(); i++)	
		cout << V1.getItem(i) << endl;

	int x;
	cout<<"\nEnter a number to search for:";
	cin>>x;
	int ind = V1.getIndex(x);
	if(ind != -1)
		cout<<endl<<x<<" is found at index:"<<ind;
	else
		cout<<endl<<x<<" NOT found";


	//instantiate a version of MyList for string Type
	n = 5;
	MyList <string>V2(n);

	cout<<"\nPlease enter 5 words:";

	string s;		
	for(i=0; i<n; i++)
	{
		cin>>s;
		V2.addItem(s);
	}

	cout << "\nPrinting V2 contents:" << endl;
	for (i = 0; i < V2.getCount(); i++)
		cout << V2.getItem(i) << endl;

	cout<<"\nEnter a word to search for:";
	cin>>s;
	ind = V2.getIndex(s);
	if(ind != -1)
		cout<<endl<<s<<" is found at index:"<<ind;
	else
		cout<<endl<<s<<" NOT found";
	
	return 0;
}
