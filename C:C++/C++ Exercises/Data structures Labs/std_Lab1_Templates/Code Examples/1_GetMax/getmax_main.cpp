/*
******** File Description ********
Assume you want to write a function GetMax that returns the maximum of three variables of any type. 
Without templates, you must write an overloaded function with the name GetMax for each type. 
Using templates enables you write the function code once then use it for any type.
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//Function Template definition
/* Both the word "class" and "typename" here mean any built-in or user-defined type.
	The compiler will not compile a function template until the generic type T is specified. 
    i.e. until you make a call statement for the function.
	When a template-function-call statement is encountered by the compiler, 
	it generates a version of the function with the type specified by the call statement. 
	Hence each call statement generates an overloaded function with the name GetMax but with different parameter types.

*/
template <typename T> //or template <class T>
T GetMax(T a, T b, T c)
{
	cout<<"\nGetMax 'Template' version is called";	//this line is just for code trace and explanation
	T max = a;
	if (b>max) max = b;
	if (c>max) max = c;
	return max;
}

template <typename T> //or template <class T>
T Getmin(T* array, int size)
{
	T min = array[0]; 

	for (int i = 0; i < size; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}

	return min;
}

//[Q1] after 1st run, uncomment the following function definition

//The function template can be overloaded with another function
//char* GetMax(char* a,char* b,char* c)
//{
//	cout<<"\nGetMax 'char*' version is called";	//this line is just for code trace and explanation
//	char* max = new char[100];	//just for simlplicity assume none of the strings is longer than 100
//	strcpy(max,a);
//	if(strcmp(b, max) > 0 ) 
//		strcpy(max, b);
//	if(strcmp(c, max) > 0 ) 
//		strcpy(max, c);
//	return max;
//
//}


//Using the Function Template
int main()
{
	int array_int[5] = { 1,4,5,0,3 };
	int min_int;

	double array_double[5] = { 0.5, 0.2, 0.1, 0.05, 0.005 };
	double min_double;

	int x = 10, y = 20, z = 9;
	double w, k, l = 52.5, m = 34.67, n = 12.4;
	char ch1, ch2 = 't', ch3 = 'd', ch4 = 'v';

	//using GetMax with int variables
	w = GetMax(x, y, z);
	cout << "\nMaximim integer number is " << w << endl;

	//using GetMax with double variables
	k = GetMax(l, m, n);
	cout << "\nMaximim double number is " << k << endl;

	//using GetMax with char variables
	ch1 = GetMax(ch2, ch3, ch4);
	cout << "\nMaximim character is '" << ch1 << '\'' << endl;

	char name1[30] = "Hani Farouk";
	char name2[50] = "Safaa Mahmoud";
	char name3[20] = "Ahmed Emad";
	char *res;

	min_int = Getmin(array_int, 5);

	cout << "\nMinimum value in the int array is " << min_int << endl;

	min_double = Getmin(array_double, 5);
	cout << "\nMinimum value in the double array is " << min_double << endl;

	//using GetMax with char* variables
	res = GetMax(name1, name2, name3);
	cout << "\nMaximim names is '" << res << '\'' << endl;


	//============================= Q2 + answer  ==================================
	// [Q2] after finishing Q1,
	//	Uncomment the following two lines, then answer the questions below 

	//w = GetMax(x, y, m);	//Line to uncomment
	//cout << "Maximim double is '" << w << '\'' << endl;

	//	What's the problem? How can you fix it so that w = 34.67?
	//	Hint: There are two ways, can you think of both of them?
	//	Think then see the answer below
	

	//Answer:
	//1st way is to cast each parameter. Check next line
	//w = GetMax((double)x,(double) y, m);
	//2nd way is to tell the compiler you want the "double" version of the function
	//Here the compiler performs castig for your parameters. Check next line.
	//w = GetMax<double>(x, y, m); 
	
	
	cin>>ch1;		//just to stop the program to see the output window	
	return 0;
}
