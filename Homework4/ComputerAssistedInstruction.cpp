//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #4 -											//
// Exercises  6.57, 6.58, 6.59, 6.60, and 6.61		//
//													//
// 2/12/2020										//
//													//
//ComputerAssistedInstruction class.				//
//It has all the functions to support the CAI		//
// for math operations and engage the user with		//
//motivational quotes and different levels.			//
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include "ComputerAssistedInstruction.h"

//Random generators for 2 integers, with upper and lower levels.
void ComputerAssistedInstruction::randomNumbersGenerator(int lower, int upper, int& num1, int& num2)
{
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomInt{ static_cast<unsigned int>(lower), static_cast<unsigned int>(upper)};
	num1 = randomInt(engine);
	num2 = randomInt(engine);
}

//Overload randomNumberGenerator to return 1 random integer.
void ComputerAssistedInstruction::randomNumbersGenerator(int lower, int upper, int& num1)
{
	int num2{ 0 };
	randomNumbersGenerator(lower, upper, num1, num2);
}

//Setter for the math operations
void ComputerAssistedInstruction::setMathOperation(Operations op)
{
	operation = op;
}

//Getter for the math operations
ComputerAssistedInstruction::Operations ComputerAssistedInstruction::getMathOperation()
{
	return operation;
}

//Getters for the user's successes
int ComputerAssistedInstruction::getSuccesses()
{
	return successes;
}

//Getters for the user's failures
int ComputerAssistedInstruction::getFailures()
{
	return failures;
}

//Getters for the user's number of trials
int ComputerAssistedInstruction::getNumberOfTrials()
{
	return numberOfTrials;
}

//Getters for the user's rate of success. Calculate the rate.
double ComputerAssistedInstruction::getRateOfSuccess()
{
	rateOfSuccess = static_cast<double>(successes) / (static_cast<double>(failures) + static_cast<double>(successes));
	return rateOfSuccess*100;
}

//Perform math operation.
int ComputerAssistedInstruction::mathOperationPerformer(int num1, int num2)
{
	int result{ 0 };
	switch (operation)
	{
	case Operations::Add:
		result = num1 + num2;
		break;
	case Operations::Subtract:
		result = num1 - num2;
		break;
	case Operations::Multiply:
		result = num1 * num2;
		break;
	case Operations::Divide:
		result = num1 / num2;
		break;
	default:
		result = -1;
		break;
	}
	return result;
}

//Prepare the math question to the user
std::string ComputerAssistedInstruction::mathQuestion(int num1, int num2)
{
	std::string question{ "" };
	question += "How much is " + std::to_string(num1) + " " + ComputerAssistedInstruction::OperationsString[static_cast<int>(operation)] + " " + std::to_string(num2);
	return question;
}

//Return motivational quotes to the users
std::string ComputerAssistedInstruction::mathAnswer(bool correct)
{
	int quoteNumber{ 0 };
	std::string answerString{ "" };
	
	if (correct)
	{
		randomNumbersGenerator(0, correctAnswersString.size() -1, quoteNumber);
		answerString = correctAnswersString[quoteNumber];
		successes++;
		numberOfTrials++;
	}
	else
	{
		randomNumbersGenerator(0, wrongAnswersString.size() -1, quoteNumber);
		answerString = wrongAnswersString[quoteNumber];
		failures++;
		numberOfTrials++;
	}
	return answerString;
}
