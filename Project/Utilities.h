//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/4/2020											//
//													//
// This is the header file for the Utilities class.	//
// It declares static functions to input and		//
// valdiate the input value.						//
//////////////////////////////////////////////////////

class Utilities
{
public:

	//Get user input and validate it's a valid integer.
	//Use pointers to get the strings for the prompts.
	static int getIntInputValidate(std::string*, std::string*);
	static double getDoubleInputValidate(std::string, std::string);

	//Random numbers generators
	static void randomNumbersGenerator(int lower, int upper, int& num1, int& num2);
	static void randomNumbersGenerator(int lower, int upper, int& num1);
	static void uniqueRandomNumbersGenerator(int lower, int upper, int numberOfRandomNumbers, std::vector<int>&);
	
};
