// Fig. 6.26: fig06_26.cpp
// Function template maximum test program
#include <iostream>
#include "maximum.h" //include definition of function template maximum
using namespace std;

int main()
{
	// demonstrate maximum with int values
	int int1, int2, int3, int4;

	cout << "Input four integer values: ";
	cin >> int1 >> int2 >> int3 >> int4;

	// invoke int version of maximum
	cout << "The maximum integer value is: "
		<< maximum(int1, int2, int3, int4);

	// demonstrate maximum with double values
	double double1, double2, double3, double4;

	cout << "\n\nInput four double values: ";
	cin >> double1 >> double2 >> double3 >> double4;

	// invoke double version of maximum
	cout << "The maximum double value is: "
		<< maximum(double1, double2, double3, double4);

	// demonstrate maximum with char values
	char char1, char2, char3, char4;

	cout << "\n\nInput four char values: ";
	cin >> char1 >> char2 >> char3 >> char4;

	// invoke char version of maximum
	cout << "The maximum char value is: "
		<< maximum(char1, char2, char3, char4);
} // end main