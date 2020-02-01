//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 5.2										//
//													//
// 2/1/2020											//
//												    //
// This is file for the Exercise 5.2.				//
// It demonstrates adding an argument with a default//
// value.											//
//////////////////////////////////////////////////////

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// Class that has a function to return the max value of
// 4 integers. The fourth one is only included if it's
// less than 1000000.
class Maximum
{
public:
	// Compares 4 integers and returns the largest one. Num4 is included
	// only if it's less than 1000000.
	int GetMaximumValue(int num1, int num2, int num3, int num4 = 1000000)
	{
		int maxValue = num1;
		if (num2 > maxValue)
			maxValue = num2;
		if (num3 > maxValue)
			maxValue = num3;
		if ((num4 < 1000000) && (num4 > maxValue)) //Checks if num4 should be included in the comparaison
			maxValue = num4;

		return maxValue;
	}
};

//Driver function for Exercise 5.2.
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

	// Calling function GetMaximumValue without the fourth parameter (old interface)
	cout << "Max Value (without number 4) = " << max.GetMaximumValue(num1, num2, num3) << endl;

	cout << "Enter fourth number: ";
	cin >> num4;
	// Calling function GetMaximumValue with the fourth parameter (new interface)
	cout << "Max Value (with number 4) = " << max.GetMaximumValue(num1, num2, num3, num4) << endl;

	return 0;
}
