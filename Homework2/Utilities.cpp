//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #2 -  Exercise 4.14 p150						//
//													//
// 1/27/2020										//
//													//
// This is the Utilities class.						//
// It declares static functions to input and		//
// valdiate the input value.						//
//////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "Utilities.h"

//Function that will input a string from the user and make sure it's an integer.
//If it's not an integer, it will give an error message and offer the user to enter the value again.
int Utilities::getIntInputValidate(std::string prompt, std::string inputName)
{
	//Variables used by the function
	bool invalidNumber = true; //Boolean variable used by the loop to check when to stop.
	char yesNo = 'Y';
	std::string inputIntString{ "" };
	int inputNumber{ 0 };

	//do-while loop to input an integer value from the user, as a string first. 
	//If the value entered is not an integer, it will print out an error message
	//and offer the user to try again or stop.
	do
	{
		std::cout << prompt;
		std::cin >> inputIntString;
		try
		{
			inputNumber = std::stoi(inputIntString);
			invalidNumber = false;
		}
		catch (std::invalid_argument ia)
		{
			std::cout << "Invalid " << inputName << " entered! \n";
			std::cout << "Error: " << ia.what() << ". \n";
			std::cout << "Try again? Y/N: ";
			std::cin >> yesNo;
			if (!((yesNo == 'Y') || (yesNo == 'y')))
			{
				inputNumber = -1;
				break;
			}
		}
	} while (invalidNumber);

	return inputNumber;
}

double Utilities::getDoubleInputValidate(std::string prompt, std::string inputName)
{
	//Variables used by the function
	bool invalidNumber = true; //Boolean variable used by the loop to check when to stop.
	char yesNo = 'Y';
	std::string inputDoubleString{ "" };
	double inputNumber{ 0.0 };

	//do-while loop to input an integer value from the user, as a string first. 
	//If the value entered is not an integer, it will print out an error message
	//and offer the user to try again or stop.
	do
	{
		std::cout << prompt;
		std::cin >> inputDoubleString;
		try
		{
			inputNumber = std::stod(inputDoubleString);
			invalidNumber = false;
		}
		catch (std::invalid_argument ia)
		{
			std::cout << "Invalid " << inputName << " entered! \n";
			std::cout << "Error: " << ia.what() << ". \n";
			std::cout << "Try again? Y/N: ";
			std::cin >> yesNo;
			if (!((yesNo == 'Y') || (yesNo == 'y')))
			{
				inputNumber = -1;
				break;
			}
		}
	} while (invalidNumber);

	return inputNumber;
}
