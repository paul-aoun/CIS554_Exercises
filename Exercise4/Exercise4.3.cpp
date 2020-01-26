//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Exercise 4.3										//
//													//
// 1/25/2020										//
//												    //
// This is the main file for Exercise 4.2.			//
// It will output "Expression is TRUE" regardless	//
// of the value of the variables bool2 and bool4.	// 
//////////////////////////////////////////////////////

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool bool1 = true;
	bool bool2 = false;
	bool bool3 = false;
	bool bool4 = true;

	//Using || with an expression and it's negative will always be true.
	//Thus, regardless of the value of bool2 and bool4, it will always output "Expression is TRUE"
	if ((bool1 && bool3) || (bool2 && bool4) || !(bool2 && bool4))
	{
		cout << "Expression is TRUE" << endl;
	}
	else
	{
		cout << "Expression is FALSE" << endl;
	}

	return 0;
}
