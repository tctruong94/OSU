#include <iostream>
#include <math.h>
#include "Point.hpp"
#include "LineSegment.hpp"
using namespace std;

int main()
{
	//declare the classes
	Point p1(4.0, 7.0);
	Point p2(5.0, 8.0 );

	LineSegment ls1(p1, p2);

	//declare variables
	double length = ls1.length();
	double slope = ls1.slope();

	//output text for testing
	cout << "This program will calculate the length and slope of line segment ls1.\n";
	cout << "The length is: " << length << ".\n";
	cout << "The slope is: " << slope << ".\n";

	return 0;
}

