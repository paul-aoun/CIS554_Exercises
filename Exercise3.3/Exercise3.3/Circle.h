///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 3_3 - Circle Class header file
// Date - 1/15/2020
///////////////////////////////////////////////

class Circle
{

public:
		
	explicit Circle(double);

	void setRadius(double);
	double getRadius();

	double getDiameter();
	double getCircumference();
	double getArea();

private:
	double radius, diameter, circumference, area;
	
	//Calculates and sets the circle's metrics
	void calculateCircleMetrics();

};
#pragma once
