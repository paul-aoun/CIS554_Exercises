// Exercise3.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Circle.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    double radius = 0.0;
    
    while (radius >= 0) {
       
        cout << "Enter Circle radius or negative number to stop " << endl;
        cin >> radius;

        if (radius >= 0) {
            Circle circle = Circle(radius);

            cout << "Circle Diameter is " << circle.getDiameter() << endl;
            cout << "Circle Circumference is " << circle.getCircumference() << endl;
            cout << "Circle Area is " << circle.getArea() << endl;
        } 
    }
    
    return 0;
}