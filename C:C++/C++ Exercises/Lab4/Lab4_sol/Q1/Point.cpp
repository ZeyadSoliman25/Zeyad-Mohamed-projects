#include "Point.h"
#include <iostream>

using namespace ::std;

void Point :: display(void) 
{
	cout << "(" << x << "," << y << ")";
}


Point::Point(double X, double Y) {
	set_value(X, Y);
}

Point::Point() {

}

void Point::set_value(double X, double Y) {
	x = X;
	y = Y;
}
