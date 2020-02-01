//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 5.3										//
//													//
// 2/1/2020											//
//												    //
// This is file for the Exercise 5.3.				//
// It demonstrates functions overloading.			//
//////////////////////////////////////////////////////

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// Class that has a function to return the max value of
// 3 or 4 integers. Demonstrates functions overloading.
class Maximum
{
public:
	// Compares 3 integers and returns the largest one.
	int GetMaximumValue(int num1, int num2, int num3)
	{
		std::cout << "GetMaximumValue with 3 parameters was called \n";
		
		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;
		
		return maxValue;
	}

	// Compares 4 integers and returns the largest one. 
	int GetMaximumValue(int num1, int num2, int num3, int num4)
	{
		std::cout << "GetMaximumValue with 4 parameters was called \n";

		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;
		if (num4 > maxValue)
			maxValue = num4;

		return maxValue;
	}
};

//Driver function for Exercise 5.3.
int main()
{
	int num1{ 0 };
	int num2{ 0 };
	int num3{ 0 };
	int num4{ 0 };

	Maximum max;

	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << "Enter third number: ";
	cin >> num3;

	// Calling function GetMaximumValue with 3 parameters.
	cout << "Max Value (with 3 parameters) = " << max.GetMaximumValue(num1, num2, num3) << endl;

	cout << "Enter fourth number: ";
	cin >> num4;
	// Calling function GetMaximumValue with 4 parameters.
	cout << "Max Value (with number 4) = " << max.GetMaximumValue(num1, num2, num3, num4) << endl;

	return 0;
}
