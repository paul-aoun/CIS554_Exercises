///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 3_3 - Circle Class file
// Date - 1/15/2020
///////////////////////////////////////////////

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Circle.h"

using std::cout;
using std::cin;

//Constructor to initialize the object and set the radius.
Circle::Circle(double rad) : radius(rad)
{
	//Calculate circle metrics on initialization
	calculateCircleMetrics();
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
	//Recalculate circle metrics when the radius is changed
	calculateCircleMetrics();
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getDiameter()
{
	return diameter;
}

double Circle::getCircumference()
{
	return circumference;
}

double Circle::getArea()
{
	return area;
}

//Calculates and sets the circle's metrics
void Circle::calculateCircleMetrics()
{
	diameter = 2.0 * radius;
	circumference = 2.0 * M_PI * radius;
	area = M_PI * pow(radius, 2);
}