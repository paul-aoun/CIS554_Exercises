//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 5.5										//
//													//
// 2/1/2020											//
//												    //
// This is the main file demoing					//
// recursive function. the function will add number	//
// from 1 to N, similar to a factorial function 	//
// but adding instead of multiplying.				//
//													//
//////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Utilities.h"

// Function that will recusively add the numbers from
// 1 to passed number.
int recursiveAdd(int number)
{
	// Base condition for recursive function
	if (number <= 1)
	{
		return number;
	}
	else
	{	
		// Recursively adds the numbers from 1 to number
		return number + recursiveAdd(number - 1);
	}
}

int main()
{
	int inputInteger{ 0 };

	std::cout << "Welcome to Exercise 5.4 - Program will add input number N from 1 to N. \n";

	// Loop asking user to input a number and then it will call the recursive function recursiveAdd 
	// to add the numbers from 1 to input number. It will exit for -1 (or any negative number).
	while (inputInteger >= 0) 
	{
		inputInteger = Utilities::getIntInputValidate("Please enter integer (-1 to stop): ", "integer");
		if (inputInteger < 0)
		{
			break;
		}
		std::cout << "Result: " << recursiveAdd(inputInteger) << "\n";
	}
	
}