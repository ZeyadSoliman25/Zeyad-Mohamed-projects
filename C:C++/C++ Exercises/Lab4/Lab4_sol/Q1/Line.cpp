#include "Line.h"
#include <iostream>

using namespace ::std;

Line::Line(double X1, double Y1, double X2, double Y2) {
	P1.set_value(X1, Y1);
	P2.set_value(X2, Y2);
}

void Line::Display(void)
{
	P1.display();
	P2.display();
}

Line::Line() {

}
