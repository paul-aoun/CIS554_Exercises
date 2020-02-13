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
//Header for ComputerAssistedInstruction class.		//
//It has all the functions to support the CAI		//
// for math operations.								//
//////////////////////////////////////////////////////
#include <array>
#include <string>

class ComputerAssistedInstruction
{

public:	
	//Allowed math operations
	const enum class Operations { Add, Subtract, Multiply, Divide };
	const std::array<std::string, 4> OperationsString = { std::string("plus"), std::string("minus"), std::string("times"), std::string("divided by (dividend)") };
	
	//Motivational quotes
	const std::array<std::string, 4> correctAnswersString = { std::string("Very good!"), std::string("Excellent!"), std::string("Nice work!"), std::string("Keep up the good work!") };
	const std::array<std::string, 4> wrongAnswersString = { std::string("No. Please try again."), std::string("Wrong. Try once more."), std::string("Don't give up!"), std::string("No. Keep trying") };
	
	//Random generators for 1 or 2 numbers, with upper and lower levels
	void randomNumbersGenerator (int lower, int upper, int&, int&);
	void randomNumbersGenerator(int lower, int upper, int&);

	//Setter and getter for the math operations
	void setMathOperation(Operations);
	Operations getMathOperation();
	
	//Getters for the user's successes, failures, and total number of trials
	int getSuccesses();
	int getFailures();
	int getNumberOfTrials();

	//Calculate the rate of success for the user's trials
	double getRateOfSuccess();

	//Perform math operation. 
	int mathOperationPerformer(int, int);

	//Prepare the math question to the user
	std::string mathQuestion(int, int);

	//Return motivational quotes to the users
	std::string mathAnswer(bool correctAnswer);

private: 
	Operations operation;
	int number1{ 0 }, number2{ 0 };
	int successes{ 0 }, failures{ 0 }, numberOfTrials{ 0 };
	double rateOfSuccess{ 0.0 };
};
