//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Exercise 4.1 - Part C							//
//													//
// 1/23/2020										//
//												    //
// This is the main file with a function for Part C	//
//////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//Function implementing Part C. The program will output the days in 
//reverse order, and then output "Not an allowable day number"
void partC() {

	for (int currentDay = 7; currentDay >= 0; currentDay--)

		switch (currentDay)
		{
		case 1:
			cout << "Day " << currentDay << " = Sunday \n";
			break;
		case 2:
			cout << "Day " << currentDay << " = Monday \n";
			break;
		case 3:
			cout << "Day " << currentDay << " = Tuesday \n";
			break;
		case 4:
			cout << "Day " << currentDay << " = Wednesday \n";
			break;
		case 5:
			cout << "Day " << currentDay << " = Thursday \n";
			break;
		case 6:
			cout << "Day " << currentDay << " = Friday \n";
			break;
		case 7:
			cout << "Day " << currentDay << " = Saturday \n";
			break;
		case 0:
		default: cout << "Not an allowable day number \n";
			break;
		}
}

//The requirements could have been implemented in 1 program with three functions. Broken in 3 programs to follow the requirements.
/*int main()
{

	partC();

	return 0;
}*/