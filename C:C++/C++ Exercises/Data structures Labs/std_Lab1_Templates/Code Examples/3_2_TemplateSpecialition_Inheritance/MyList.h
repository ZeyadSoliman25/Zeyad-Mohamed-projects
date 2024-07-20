#pragma once
#include <string>
using namespace std;



//Class Template
//MyList - a simple templatized list
template <typename T>  //or template <class T>
class MyList
{		
protected:
	int count;
	T* data;
	int MaxCount;

public:
	MyList(int maxCnt)
	{
		count = 0;
		MaxCount = maxCnt;
		data = new T[MaxCount];
	}

	int getCount()
	{	//Actual number of items stored
		return count;
	}
	
	bool addItem(T Item)	//Adds a new Item to the array
	{
		if(count == MaxCount ) return false;

		data[count++] = Item;
		return true;
	}	
	
	T getItem(int index)	//gets an Item at a given index
	{
		return data[index];
	}

	int getIndex(T Item)	//returns the index of a given Item
	{
		for(int i=0; i<count; i++)
			if (data[i] == Item)
				return i;
		return -1;	//Item no found
	}
};




