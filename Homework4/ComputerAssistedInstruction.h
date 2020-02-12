#include <array>
#include <string>

class ComputerAssistedInstruction
{

public:	
	const enum class Operations { Add, Subtract, Multiply, Divide };
	const std::array<std::string, 4> OperationsString = { std::string("plus"), std::string("minus"), std::string("times"), std::string("divided by (dividend)") };
	const std::array<std::string, 4> correctAnswersString = { std::string("Very good!"), std::string("Excellent!"), std::string("Nice work!"), std::string("Keep up the good work!") };
	const std::array<std::string, 4> wrongAnswersString = { std::string("No. Please try again."), std::string("Wrong. Try once more."), std::string("Don't give up!"), std::string("No. Keep trying") };
	
	void randomNumbersGenerator (int lower, int upper, int&, int&);
	void randomNumbersGenerator(int lower, int upper, int&);
	void setMathOperation(Operations);
	Operations getMathOperation();
	int mathOperationPerformer(int, int);
	std::string mathQuestion(int, int);
	std::string mathAnswer(bool correctAnswer);

private:
	Operations operation;
	int number1{ 0 }, number2{ 0 };
};
