#include <iostream>
#include <string>
using namespace std;

//Recusive version for factorial function
int Factorial(int n)
{
	if (n == 0) return 1;
	else return n * Factorial(n - 1);
}


//Factorial_Demo
//To illustrate how factorial works
int Factorial_Demo(int n)
{
	static int cnt = 0;
	cout << endl << std::string(15*cnt++, ' ');
	cout << "Fact(" << n << ")";
	if (n == 0) {
		cnt--;  return 1;
	}
	else
	{
		cout << "==>Calls Fact(" << n - 1 << ")...";
		int Fprev = Factorial_Demo(n - 1);
		cout << endl << std::string(15 * cnt, ' ');
		cout << "<=== Fact(" << n - 1 << ") returns " << Fprev<<endl;
		cout << endl << std::string(15 * (--cnt), ' ');
		cout << "Back inside Fact(" << n << "),return "<<n<<"*Fact("<<n-1<<")";
		
		return n*Fprev;
	}
}



int main()
{
	int n = 5;
	cout << "Main calls Fact(" << n << ")";
	int x = Factorial_Demo(n);
	cout << "\n\nFact(" << n << ") returns " << x << endl;
	string s;
	getline(cin, s); //just to pause console (output) screen
	return 0;
	
}