#pragma once
#include "Car.h"
#include "MyList.h"


//To make a generic template class work on a user-defined type,
//Solution2: inheritance

//Customizing the generic template (MyList) to work on Car objects 
//through inheritance then overriding functions with new behaviour only 
class CarList:public MyList<Car>
{
public:
	CarList(int maxCnt):MyList(maxCnt) //new class must have its own constructor as constructors are not inherited from base class
	{}
	

	bool addItem(Car Item)	//Adds a new Car to the array but sorted by Car year
	{
		if(count == 0 ) 
		{
			data[count++] = Item; 
			return true; 
		}
		if(count == MaxCount ) return false;
		int i;
		for(i=count-1; i>=0; i--)
			if(data[i].year > Item.year)	//when found ==> shift
					data[i+1] = data[i];
			else
				break;
		
		data[i+1] = Item;
		count++;
		return true;
	}	
	
	// a new functionality added to class CarList not found in MyList
	int GetCheapest()	//returns the cheapest car index
	{
		if(!count) return -1;	//no cars in the list yet
		double min = data[0].price;
		int ind=0;
		for(int i=0; i<count; i++)
			if(data[i].price < min)
			{
				min =data[i].price;
				ind = i;
			}
		return ind;	//returns index of cheapest car (min price)

	}


};
