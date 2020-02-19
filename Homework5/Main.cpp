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
	bool continueLooping{ true };
	int choice{ 0 }; //user choice
	std::string answer{ "" }, questionStr{ "" }, correctAnswer{ "" };
	bool questionIsTrue{ false };
		
	//Loop until the user enters an integer for difficulty level or exists
	while (continueLooping)
	{

		std::cout << "Welcome to Presidents' Day Trivia! \n\n";
		std::cout << "Option 1: Refresh your memory about the United States Presidents to date. \n";
		std::cout << "Option 2: Questions about the Presidents focusing on their presidency's number. \n";
		std::cout << "Option 3: Trivia about the Presidents. \n";

		choice = Utilities::getIntInputValidate("\nPlease enter your choice 1 to 3 (-1 to exit): ", "Invalid Choice. Please try again.");
		switch (choice) {
		case 1:
			std::system("CLS");
			std::cout << "\n" << pd.printPresidents() << "\n";
			continueLooping = true;
			break;
		case 2:
			std::system("CLS");
			pd.askPresidentQuestion(questionIsTrue, questionStr, correctAnswer);
			std::cout << questionStr <<": ";
			std::cin >> answer;
			if ((((answer == "Y") || (answer == "y")) && questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && !questionIsTrue))
			{
				std::cout << "Your answer is correct! You certainly know your history!\n\n";
			}
			else if ((((answer == "Y") || (answer == "y")) && !questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && questionIsTrue))			
			{
				std::cout << "You answer is wrong! " << correctAnswer <<"\n\n";
			}
			continueLooping = true;
			break;
		case 3:
			std::system("CLS");
			std::cout << "\n" << pd.printPresidents();
			break;
		case -1:
			continueLooping = false;
			break;
		default:
			continueLooping = true;
			break;
		}
	}   
}