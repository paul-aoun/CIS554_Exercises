//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/4/2020											//
//													//
// This is the Utilities class.						//
// It declares static functions to input and		//
// valdiate the input value.						//
//////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <vector>
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
				inputNumber = -10;
				break;
			}
		}
	} while (invalidNumber);

	return inputNumber;
}

//Function that will input a string from the user and make sure it's a double.
//If it's not a double, it will give an error message and offer the user to enter the value again.
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
				inputNumber = -10;
				break;
			}
		}
	} while (invalidNumber);

	return inputNumber;
}

//Random generators for 2 integers, with upper and lower levels.
void Utilities::randomNumbersGenerator(int lower, int upper, int& num1, int& num2)
{
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomInt{ static_cast<unsigned int>(lower), static_cast<unsigned int>(upper) };
	num1 = randomInt(engine);
	num2 = randomInt(engine);
}

//Overload randomNumberGenerator to return 1 random integer.
void Utilities::randomNumbersGenerator(int lower, int upper, int& num1)
{
	int num2{ 0 };
	randomNumbersGenerator(lower, upper, num1, num2);
}

//Return n random numbers between lower and upper.
void Utilities::uniqueRandomNumbersGenerator(int lower, int upper, int numberOfRandomNumbers, std::vector <int>& randomNumbers)
{
	int num1{ 0 };
	int num2{ 0 };
	std::vector<int>::iterator it;
	
	std::vector <int> sequentialNumbers;

	for (int i = 0; i < numberOfRandomNumbers; i++) {
		sequentialNumbers.push_back(i);
	}

	while (sequentialNumbers.size() > 0) {
		randomNumbersGenerator(lower, sequentialNumbers.size() -1, num1, num2);
		randomNumbers.push_back(sequentialNumbers.at(num1));
		sequentialNumbers.erase(sequentialNumbers.begin() + num1);
	}
}
