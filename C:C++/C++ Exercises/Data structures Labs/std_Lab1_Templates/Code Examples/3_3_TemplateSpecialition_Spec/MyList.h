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

	virtual int getIndex(T Item)	//returns the index of a given Item
	{
		for(int i=0; i<count; i++)
			if (data[i] == Item)
				return i;
		return -1;	//Item no found
	}
};




//Customizing the generic template (MyList) to work on char*
//through class template specilaization
template <>
class MyList<char*>	//specilaized version of MyList for char* type
{
private:
	int count;
	char** data;
	int MaxCount;

public:
	MyList(int maxCnt)
	{
		count = 0;
		MaxCount = maxCnt;
		data = new char*[MaxCount];
		for(int i=0; i<MaxCount; i++)
			data[i] = nullptr;
	}

	int getCount()
	{	//Actual number of items stored
		return count;
	}
	
	bool addItem(char* Item)	//Adds a new Item to the array
	{
		if(count < MaxCount )
		{
			if(data[count])		//if this pointer alreday has mem reserved, free it
				delete []data[count];
			//Allocate new memory with size equal to the new Item length (+1 for null)
			data[count] = new char[strlen(Item)+1];
			strcpy(data[count],Item);	//copy data from Item to the array (data[count])
			count++;
			return true;
		}
		return false;
	}	
	
	char* getItem(int index)	//gets an Item at a given index
	{
		char* retValue = new char[strlen(data[index]) + 1];
		strcpy(retValue, data[index]);
		return retValue;
	}

	int getIndex(char* Item)	//returns the index of a given Item
	{
		for(int i=0; i<count; i++)
			if (!strcmp(data[i],Item))
				return i;
		return -1;	//Item no found
	}
};


