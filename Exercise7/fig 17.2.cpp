// Fig. 17.2: fig17_02.cpp
// Example that throws exceptions on
// attempts to divide by zero.
#include <iostream>
#include "DivideByZeroException.h"
#include "NumberTooLargeException.h"

using namespace std;

// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient(int numerator, int denominator) {
	// throw DivideByZeroException if trying to divide by zero
	if (denominator == 0) {
		throw DivideByZeroException{}; // terminate function
	}

	// return division result
	return static_cast <double>(numerator) / denominator;
}

// perform multiplication and throw NumberTooLargeException object if
// the result is greater than MAX_NUMBER
double multiplication(int number1, int number2) {
	// throw NumberTooLargeException if result greater than MAX_NUMBER
	if (number1*number2 > NumberTooLargeException::MAX_NUMBER) {
		throw NumberTooLargeException{}; // terminate function
	}

	// return division result
	return static_cast <double>(number1)*number2;
}

/*
int main() {
	int number1; // user-specified numerator
	int number2; // user-specified denominator

	cout << "Enter two integers (end-of-file to end): ";

	// enable user to enter two integers to divide
	while (cin >> number1 >> number2) {
		// try block contains code that might throw exception
		// and code that will not execute if an exception occurs
		try {
			double result{ quotient(number1, number2) };
			cout << "The quotient is: " << result << endl;
			
			result = multiplication(number1, number2);
			cout << "The multiplication result is: " << result << endl;
		}
		catch (const DivideByZeroException & divideByZeroException) {
			cout << "Exception occurred: "
				<< divideByZeroException.what() << endl;
		}
		catch (const NumberTooLargeException & numberTooLargeException) {
			cout << "Exception occurred: "
				<< numberTooLargeException.what() << endl;
		}

		cout << "\n Enter two integers (end-of-file to end): ";
	}

	cout << endl;
}
*/