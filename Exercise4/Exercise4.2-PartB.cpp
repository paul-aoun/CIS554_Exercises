//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Exercise 4.2 - Part B							//
//													//
// 1/25/2020										//
//												    //
// This is the main file with a function for Part B	//
//////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//Function implementing Part B. The program will output the days in 
//order and will skip Thursday using continue. 
void partB() {

	for (int currentDay = 1; currentDay <= 7; currentDay++) 

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
			continue; //Using continue to skip Thursday
			cout << "Day " << currentDay << " = Thursday \n";
			break;
		case 6:
			cout << "Day " << currentDay << " = Friday \n";
			break;
		case 7:
			cout << "Day " << currentDay << " = Saturday \n";
			break;
		default: cout << "Not an allowable day number \n";
			break;
		}
}

//The requirements could have been implemented in 1 program with three functions. Broken in 3 programs to follow the requirements.
int main()
{

	partB();

	return 0;
}