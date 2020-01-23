//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Exercise 4.1 - Part A							//
//													//
// 1/23/2020										//
//												    //
// This is the driver file for Part 1.				//
// It has the fix to the switch statement.			//
//													//
//////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	for (int currentDay = 1; currentDay <= 7; currentDay++)

		switch (currentDay)
		{
		case 1:
			cout << "Day " << currentDay << " = Sunday" << endl;
			break;
		case 2:
			cout << "Day " << currentDay << " = Monday" << endl;
			break;
		case 3:
			cout << "Day " << currentDay << " = Tuesday" << endl;
			break;
		case 4:
			cout << "Day " << currentDay << " = Wednesday" << endl;
			break;
		case 5:
			cout << "Day " << currentDay << " = Thursday" << endl;
			break;
		case 6:
			cout << "Day " << currentDay << " = Friday" << endl;
			break;
		case 7:
			cout << "Day " << currentDay << " = Saturday" << endl;
			break;
		default: cout << "Not an allowable day number";
			break;
		}

	return 0;
}
