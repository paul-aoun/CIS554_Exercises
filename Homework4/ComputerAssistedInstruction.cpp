#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include "ComputerAssistedInstruction.h"

void ComputerAssistedInstruction::randomNumbersGenerator(int lower, int upper, int& num1, int& num2)
{
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomInt{ static_cast<unsigned int>(lower), static_cast<unsigned int>(upper)};
	num1 = randomInt(engine);
	num2 = randomInt(engine);
}

//Overload randomNumberGenerator
void ComputerAssistedInstruction::randomNumbersGenerator(int lower, int upper, int& num1)
{
	int num2{ 0 };
	randomNumbersGenerator(lower, upper, num1, num2);
}

void ComputerAssistedInstruction::setMathOperation(Operations op)
{
	operation = op;
}

ComputerAssistedInstruction::Operations ComputerAssistedInstruction::getMathOperation()
{
	return operation;
}

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

std::string ComputerAssistedInstruction::mathQuestion(int num1, int num2)
{
	std::string question{ "" };
	question += "How much is " + std::to_string(num1) + " " + ComputerAssistedInstruction::OperationsString[static_cast<int>(operation)] + " " + std::to_string(num2);
	return question;
}

std::string ComputerAssistedInstruction::mathAnswer(bool correct)
{
	int quoteNumber{ 0 };
	std::string answerString{ "" };
	
	if (correct)
	{
		randomNumbersGenerator(0, correctAnswersString.size() -1, quoteNumber);
		answerString = correctAnswersString[quoteNumber];
	}
	else
	{
		randomNumbersGenerator(0, wrongAnswersString.size() -1, quoteNumber);
		answerString = wrongAnswersString[quoteNumber];
	}
	return answerString;
}
