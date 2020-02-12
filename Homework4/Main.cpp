//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #3 -  Exercise 5.16 p206						//
//													//
// 2/6/2020											//
//												    //
// This is the driver file for the BarChart class.	//
// A BarChart object store the parameters			//
// of the chart.								 	//
// This files will prompt the users for the numbers //
// and plots the chart, either vertically or		//
// horizontally.									//
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "ComputerAssistedInstruction.h"
#include "Main.h"

void inputCorrectAnswer(ComputerAssistedInstruction& CAI, int num1, int num2, bool& continueLooping)
{
	bool continueLoopingInner{ true };
	int answer{ 0 };
	int result = CAI.mathOperationPerformer(num1, num2);

	while (continueLoopingInner) {


		std::cout << CAI.mathQuestion(num1, num2) << " (-10 to exit)?\n";
		answer = Utilities::getIntInputValidate("Enter the result: ", "result");

		if (answer == -10)
		{
			continueLooping = false;
			continueLoopingInner = false;
		}
		else if (result == answer)
		{
			std::cout << CAI.mathAnswer(true) + "\n";
			continueLoopingInner = false; //user got the right answer, stop and ask for new operation
		}
		else if (result != answer)
		{
			std::cout << CAI.mathAnswer(false) + "\n";
		}
	}
}

int main()
{
	bool continueLooping{ true }, continueLoopingInner{ true };

	int num1{ 0 }, num2{ 0 }, answer{ 0 };
	int lower{ 0 }, upper{ 9 };
	int choice{ 0 };

	ComputerAssistedInstruction CAI;

	//Will loop until the user exits by entering -1 for any input value. 
	//It will validate all inputs and then returns the result of the operations, 

	while (continueLooping)
	{

		//Get two single digit random integers
		CAI.randomNumbersGenerator(lower, upper, num1, num2);

		std::cout << "Please choose the math operation to perform: \n";
		std::cout << "Add: 1, Subtract: 2, Multiply: 3, or Divide: 4. \n";
		choice = Utilities::getIntInputValidate("Enter your choice (1 to 4, -10 to exit.): ", "Invalid Choice. Please try again.");

		if ((choice <= 4) && (choice >= 1))
		{
			switch (choice)
			{
			case 1:
				CAI.setMathOperation(ComputerAssistedInstruction::Operations::Add);
				inputCorrectAnswer(CAI, num1, num2, continueLooping);
				break;
			case 2:
				CAI.setMathOperation(ComputerAssistedInstruction::Operations::Subtract);
				inputCorrectAnswer(CAI, num1, num2, continueLooping);
				break;
			case 3:
				CAI.setMathOperation(ComputerAssistedInstruction::Operations::Multiply);
				inputCorrectAnswer(CAI, num1, num2, continueLooping);
				break;
			case 4:
				CAI.setMathOperation(ComputerAssistedInstruction::Operations::Divide);
				inputCorrectAnswer(CAI, num1, num2, continueLooping);
				break;
			}
		}
		else if (choice == -10)
		{
			continueLooping = false;
		}
	}
};
