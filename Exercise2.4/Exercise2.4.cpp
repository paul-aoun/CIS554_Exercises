///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 2_4 - Simple Class
// Date - 1/9/2020
///////////////////////////////////////////////

#include <iostream>
#include "SimpleMath.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// declare an object of type SimpleMath
	SimpleMath simpleMath;

	// declare some variables to work with
	int number1 = 0;
	int number2 = 0;
	int result = 0;

	// prompt user for input
	cout << "Enter first number2: ";
	cin >> number1;
	cout << "Enter second number: ";
	cin >> number2;

	// perform addition operation using the simpleMath object, then display result
	result = simpleMath.Add(number1, number2);
	cout << number1 << " + " << number2 << " = " << result << endl;

	// perform multiplication operation using the simpleMath object, then display result
	result = simpleMath.Multiply(number1, number2);
	cout << number1 << " * " << number2 << " = " << result << endl;

	return 0;
}