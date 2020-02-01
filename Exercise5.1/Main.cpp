//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 5.1										//
//													//
// 2/1/2020											//
//												    //
// This is the driver file for the TimeDiff class.	//
// It has the main function which will loop until	//
// the user enters -1. It also has a function to	//
// get integer value from the user and validate		//
// that it's an integer.							//
//////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "TimeDiff.h"

//Function that will input a string from the user and make sure it's an integer.
//If it's not an integer, it will give an error message and offer the user to enter the value again.
int getIntInputValidate(std::string inputName)
{
	//Variables used by the function
	bool invalidNumber = true; //Boolean variable used by the loop to check when to stop.
	char yesNo = 'Y';
	std::string inputIntString{ "" };
	int inputNumber{ 0 };

	//do-while loop to input an integer value from the user, as a string first. 
	//If the value entered is not an integer, it will print out an error message
	//and offer the user to try again or stop.
	do
	{
		std::cout << inputName << ": ";
		std::cin >> inputIntString;
		try
		{
			inputNumber = std::stoi(inputIntString);
			invalidNumber = false;
		}
		catch (std::invalid_argument ia)
		{
			std::cout << "Invalid " << inputName << " entered! \n";
			std::cout << "Error: " << ia.what() << ". \n";
			std::cout << "Try again? Y/N: ";
			std::cin >> yesNo;
			if (!((yesNo == 'Y') || (yesNo == 'y'))) 
			{
				inputNumber = -1;
				break;
			}
		}
	} while (invalidNumber);

	return inputNumber;
}

//Main function. It loops asking the user for the time and calculating how many seconds 
//elapsed since noon. It will exit when the user enters -1 as any time input.
/*int main()
{
	bool continueLooping{ true };

	int hour{ 0 };
	int minute{ 0 };
	int second{ 0 };
	int secondsSinceNoon{ 0 };

	TimeDiff timeDiff;

	//Will loop until the user exits by entering -1 for any time value. 
	//It will validate all inputs and then returns the seconds elapsed since noon. 
	std::cout << "Enter time below (-1 to stop): \n";
	do {
		
		hour = getIntInputValidate("hour");
		if (hour == -1)
		{
			break;
		}

		minute = getIntInputValidate("minute");
		if (minute == -1)
		{
			break;
		}

		second = getIntInputValidate("second");
		if (second == -1)
		{
			break;
		}

		secondsSinceNoon = timeDiff.SecondsSinceNoon(hour, minute, second);

		if (secondsSinceNoon == -1)
		{
			std::cout << "Invalid time entered! \n";
		}
		else
		{
			std::cout << "Seconds since previous noon = " << secondsSinceNoon << ". \n";
		}
		

	} while (true);

}*/
