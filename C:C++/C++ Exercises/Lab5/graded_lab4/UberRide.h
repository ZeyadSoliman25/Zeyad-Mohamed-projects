#pragma once
#include <iostream>
#include <string>

using namespace std;
class UberRide
{
	protected:
		string Name;
		int seatCount;
		string plateNb;
		int Price;


	public:
		void setName(string);
		bool takeNewPassenger(void);
		virtual void setPrice(int) =0;
		int getPrice(void);
		void setplateNb(string);
		virtual void printInfo(void);


};

