///////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 2_4 - SimpleMath Class definition
// Date - 1/9/2020
///////////////////////////////////////////////

#include <iostream>
#include "SimpleMath.h"
using std::cout;
using std::cin;
using std::endl;

// simple Add method
int SimpleMath::Add(int number1, int number2)
{
	int result = number1 + number2;
	return result;
}

// simple Multiply method
int SimpleMath::Multiply(int number1, int number2)
{
	int result = number1 * number2;
	return result;
}
