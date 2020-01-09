///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 2_2 - Simple Class
// Date - 1/7/2020
///////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class SimpleMath
{
private:
	int number1, number2, result = 0;

public:
	//Constroctor with 2 parameters
	SimpleMath(int num1, int num2) :
		number1(num1), number2(num2)
	{

	}


	// simple Add method
	int Add()
	{
		result = number1 + number2;
		return result;
	}

	// simple Multiply method
	int Multiply()
	{
		result = number1 * number2;
		return result;
	}
};

int main()
{
	int number1 = 5;
	int number2 = 10;

	// declare an object of type SimpleMath
	SimpleMath simpleMath(number1, number2);
	int result = 0;
		
	// perform our operation using the simpleMath object, then display result
	result = simpleMath.Add();
	cout << number1 << " + " << number2 << " = " << result << endl;

	result = simpleMath.Multiply();
	cout << number1 << " x " << number2 << " = " << result << endl;

	return 0;
}
