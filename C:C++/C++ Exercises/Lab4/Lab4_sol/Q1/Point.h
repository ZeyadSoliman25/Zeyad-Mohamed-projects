#pragma once

class Point 
{
	private:
		double x;
		double y;

	public:
		Point();
		Point(double X, double Y);
		void display(void);
		void set_value(double X, double Y);
};