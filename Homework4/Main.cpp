//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #4 -											//
// Exercises  6.57, 6.58, 6.59, 6.60, and 6.61		//
//													//
// 2/12/2020										//
//												    //
// This is the driver file for the CAI class.		//
// A CAI object stores all information needed		//
// to take the student through the math exercies 	//
// and has the functions to deliver the math testing//
// Based on the answers, it will print motivational //
// statements.										//
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "ComputerAssistedInstruction.h"

//Calculate the rate of correct answers after 10 trials and will stop looping
//when the student reaches 75% or above.
void checkRate(ComputerAssistedInstruction& CAI, bool& continueLoopingInner)
{
	//Check if number of trials is greater than 10 and then calculates rate
	if (CAI.getNumberOfTrials() >= 10)
	{
		if (static_cast <int>(CAI.getRateOfSuccess()) >= 75)
		{
			std::cout << "Congratulations, you are ready to go to the next level! \n\n";
			continueLoopingInner = false;
		}
		else
		{
			std::cout << "Please ask your teacher for extra help. \n\n";
			continueLoopingInner = false;
		}
	}
}

//Loop until the student gives the correct answer or exits.
void inputCorrectAnswer(ComputerAssistedInstruction& CAI, int num1, int num2, bool& continueLooping)
{
	bool continueLoopingInner{ true };
	int answer{ 0 };
	int result = CAI.mathOperationPerformer(num1, num2);

	//Keep looping until the student answers correctly or exits
	while (continueLoopingInner) {
	
		std::cout << CAI.mathQuestion(num1, num2) << "\n";
		answer = Utilities::getIntInputValidate("Enter the result: ", "result");

		if (result == answer)
		{
			std::cout << CAI.mathAnswer(true) + "\n";
			continueLoopingInner = false; //user got the right answer, stop and ask for new operation.
			checkRate(CAI, continueLoopingInner);
		}
		else if (result != answer)
		{//Keep looping since the student didn't get the right answer.
			std::cout << CAI.mathAnswer(false) + "\n";
			checkRate(CAI, continueLoopingInner);
		}
	}
}

//Main function to get difficulty level, math operation, and then loop testing the student until they exit
int main()
{
	bool continueLooping{ true }, continueLoopingInner{ true }, randomChoice{ false };

	int num1{ 0 }, num2{ 0 }, answer{ 0 };
	int lower{ 0 }, upper{ 9 };
	int choice{ 0 };

	ComputerAssistedInstruction CAI;

	std::cout << "Welcome to Computer Assisted Instruction! \n\n";

	//Loop until the user enters an integer for difficulty level or exists
	while ((choice <= 0) && (choice != -10))
	{
		choice = Utilities::getIntInputValidate("Please enter difficulty level (-10 to exit): ", "Invalid Choice. Please try again.");
		upper = static_cast <int>(pow(10, choice)) - 1; //Calculate upper bound for random numbers used in the math operations

		if (choice == -10)
		{
			continueLooping = false;
		}
	}

	//Will loop until the user exits. 
	//It will validate all inputs and then returns the result of the operations, including motivational messages and level upgrade 
	while (continueLooping)
	{
		std::cout << "Please choose the math operation to perform: \n";
		std::cout << "Add: 1, Subtract: 2, Multiply: 3, Divide (dividend): 4, or Random: 5. \n";
		choice = Utilities::getIntInputValidate("Enter your choice (1 to 5, -10 to exit.): ", "Invalid Choice. Please try again.");
		
		//Randomly set choice to a value between 1 and 4, if random is chosen
		if (choice == 5) 
		{
			randomChoice = true;
			
		}
		else if (choice == -10)
		{
			continueLooping = false; //user exit.
		}
	
		while ((CAI.getNumberOfTrials() < 10) && (continueLooping)) {

			if (randomChoice)
			{
				CAI.randomNumbersGenerator(1, 4, choice); //Pick a random math operation
			}
			else if (choice == -10)
			{
				continueLooping = false; //user exit.
			}

			//if valid choice, switch between the four math operations: addition, substraction, multiplication and division (dividend).
			if ((choice <= 4) && (choice >= 1) && continueLooping)
			{
				switch (choice)
				{
				case 1:
					CAI.setMathOperation(ComputerAssistedInstruction::Operations::Add);
					break;
				case 2:
					CAI.setMathOperation(ComputerAssistedInstruction::Operations::Subtract);
					break;
				case 3:
					CAI.setMathOperation(ComputerAssistedInstruction::Operations::Multiply);
					break;
				case 4:
					CAI.setMathOperation(ComputerAssistedInstruction::Operations::Divide);
					break;
				}
				
				CAI.randomNumbersGenerator(lower, upper, num1, num2);
				inputCorrectAnswer(CAI, num1, num2, continueLooping);
			}
			
		}
		
	}
};
