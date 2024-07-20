#include "ArrayStack.h"
#include "../4-Passing_Queue/LinkedQueue.h"

#include <iostream>
using namespace std;

// A function to print stack contents
//as the function should operate on a class template, the function itself should be a function template as well
template <typename T>
void PrintStack(ArrayStack<T> S)
{
	cout << endl<<"Printing stack contents: ";

	T x;
	while(S.pop(x))		
		cout << x << " ";
	
	cout<<endl;
}

//A function that takes a ArrayStack<T> S and returns its reverse (without affecting the orignal stack)
template <typename T>
ArrayStack<T> Reverse(ArrayStack<T> S)
{
	ArrayStack<T> Rev;	//First create a stack 
	T Item;
	while(S.pop(Item))	//pop from S
		Rev.push(Item); //push into Rev

	return Rev;
}
//Delete all negative element in a stack if int
//Notice that 
//   1- this function is NOT template (why?)
//	 2- S is passed by reference (why?)
void delNegative(ArrayStack<int> & S)
{
	ArrayStack<int> temp;	//First create a temp stack 
	int item;
	while (S.pop(item))	//pop from S
		if(item>=0)
			temp.push(item); //push into temp
	
	//Now temp contains non-negative items only but S is empty
	while (temp.pop(item))	//pop from temp
		S.push(item); //push into S
}


class Car {
private:
	int car_number;
	int engine_number;

public:
	int getCarNumber(void)
	{
		return car_number;
	}

	int getEngineNumber(void)
	{
		return engine_number;
	}

	void setCarNumber(int C_num)
	{
		car_number = C_num;
	}

	void setEngineNumber(int Eng_num)
	{
		engine_number = Eng_num;
	}
};


void Print_stackcars(ArrayStack<Car*> S1, int size)
{
	Car* car;
	while (S1.pop(car))
	{
		cout << "Car " << size << " info: " << "Car number: " << car->getCarNumber() << " Engine number: " << car->getEngineNumber() << endl;
		size--;
	}
}


void CatStack(ArrayStack<int> &S1, ArrayStack<int> S2)
{
	int popped_value;
	ArrayStack<int> temp;

	while (S2.pop(popped_value))
	{
		temp.push(popped_value);
	}

	while (temp.pop(popped_value))
	{
		S1.push(popped_value);
	}
}


bool SameOrder(ArrayStack<int> S1, LinkedQueue<int> Q1)
{
	ArrayStack<int> temp;
	int popped_value;
	int dequeued_value;
	int S1_size = 0;
	int Q1_size = 0;
	bool same_order = false;

	while (S1.pop(popped_value))
	{
		temp.push(popped_value);
		S1_size++;
	}

}

int main()
{
	/*Initial code for the lab*/

	/*ArrayStack<int> stack1;
	int i,x;

	//Test the 1st stack by pushing 1, 2, 3, 4 and 5 then popping them.
	cout << "Testing stack 1:" << endl;
	cout << "Pushing 5 values into stack 1:" << endl;

	//Reading From the user 5 integer values
	cout<<"Please Enter 5 integers to push in stack1:";
	for(i = 0; i < 5; i++)
	{	 
		cin>>x;
		stack1.push(x); //pushing x to stack1
	}
	cout<<"\nstack1 contents:";
	PrintStack(stack1);

	ArrayStack<int> stack2 = Reverse(stack1);
	cout<<"\nAfter Reverse...\nstack1 contents:";
	PrintStack(stack1);
	cout<<"\nstack2 contents:";
	PrintStack(stack2);

	delNegative(stack1);
	cout << "\nAfter delNegative...\nstack1 contents:";
	PrintStack(stack1);

	*/ 

	/*problem 2
	ArrayStack<Car*> stackcars;
	Car* car;
	int c_num; 
	int eng_num;

	for (int i = 0; i < 3; i++)
	{
		car = new Car();
		cout << "Enter car number: ";
		cin >> c_num;
		cout << "\nEnter engine number: ";
		cin >> eng_num;
		cout << endl;

		car->setCarNumber(c_num);
		car->setEngineNumber(eng_num);

		stackcars.push(car);
	}

	Print_stackcars(stackcars, 3);

	cout << "\n\n";
	cout << "\n================================\n problem 9 \n"; */

	/*problem 9
	ArrayStack<int> S1;
	ArrayStack<int> S2;

	S1.push(1);
	S1.push(2);
	S1.push(3);

	S2.push(4);
	S2.push(5);

	CatStack(S1, S2);
	PrintStack(S1); */

	/*problem 12*/
	ArrayStack<int> S1;
	LinkedQueue<int> Q1;
	bool same_order = false;

	for (int i = 1; i < 4; i++)
	{
		S1.push(i);
	}

	for (int i = 1; i < 4; i++)
	{
		Q1.enqueue(i);
	}

	same_order = SameOrder(S1, Q1);

	if (same_order)
	{
		cout << "They are the same";
	}
	else
	{
		cout << "They are not the same";
	}
	cout<<endl;
	return 0;


}
