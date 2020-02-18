// Homework5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Utilities.h"
#include "PresidentsDay.h"

int main()
{
    PresidentsDay pd;
	int choice{ 0 }; //user choice

	std::cout << "Welcome to Presidents' Day Trivia! \n\n";

	//Loop until the user enters an integer for difficulty level or exists
	while ((choice <= 0) && (choice != -1))
	{
		std::cout << "Option 1: Refresh your memory about the United States Presidents to date.";
		std::cout << "Option 2: Questions about the Presidents focusing on their presidency's number.";
		std::cout << "Option 3: Trivia about the Presidents.";

		choice = Utilities::getIntInputValidate("Please enter your choice 1 to 3 (-1 to exit): ", "Invalid Choice. Please try again.");
		switch (choice) {
		case 1:
			std::cout << pd.printPresidents();
			continueLooping = true;
		}
		case 2:
			std::cout << pd.printPresidents();
		if (choice == -10)
		{
			
		}
	}
    std::cout << pd.printPresidents();
   
   
}