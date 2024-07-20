#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
	Matrix <int> M1;

	int value = 0;
	bool belong_to_matrix = false;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << "Enter the value at " << i << j << ": "; 
			cin >> value;

			M1.AddValue(i, j, value);
		}
	}
	cout << '\n';

	cout << "Enter a value: ";
	cin >> value;
	cout << '\n';

	belong_to_matrix = M1.BelongTo(value);

	if (belong_to_matrix == true)
		cout << "The value "<<value<< " belongs to the matrix" << endl;
	else
		cout << "The value " << value << " doesnot belongs to the matrix" << endl;

	cout << "The max value in the matrix is:" << M1.MaxValue() << endl;

	cout << "The values in row 4 are :"<< endl;
	M1.PrintRow(4);

	cout << "The values in the list are: "<< endl; 
	M1.Print();
}