#pragma once
#include "Point.h"

class Line
{
	private:
		Point P1;
		Point P2;

	public:
		Line(double X1, double Y1, double X2, double Y2);
		Line();
		void Display(void);
		bool IsVertical(void); 
		double Getslope(void);
};