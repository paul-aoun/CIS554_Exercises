//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #5 - Presidents' Day Trivia!					//
//													//
// 2/19/2020										//
//												    //
// This is the driver file for the Trivia game.		//
// It engages the users with the 3 available play	//
// options, based on which is calls the needed		//
// functions from PresidentsDay class. It also keeps//
// the player's score.								//
/////////////////////////////////////////////////////

// Homework5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include "Utilities.h"
#include "PresidentsDay.h"

int main()
{
    PresidentsDay pd;
	bool continueLooping{ true };
	int choice{ 0 }; //user choice
	unsigned int correctAnswers{ 0 }, wrongAnswers{ 0 };
	double score{ 0.0 };
	std::string answer{ "" }, questionStr{ "" }, correctAnswer{ "" };
	bool questionIsTrue{ false };
	std::array <std::string, 4> welcomePrompts{ "Welcome to Presidents' Day Trivia! \n\n", "Option 1: Refresh your memory about the United States Presidents to date. \n",
		"Option 2: Questions about the Presidents focusing on their presidency's number. \n", "Option 3: Trivia about the Presidents. \n" };
		
	//Loop until the user enters an integer for difficulty level or exists
	while (continueLooping)
	{
		// Prints the welcome message and options for the player.
		std::cout << welcomePrompts[0];
		std::cout << welcomePrompts[1];
		std::cout << welcomePrompts[2];
		std::cout << welcomePrompts[3];

		// Depending on the user's choice, it will play one of the 3 available options:
		// 1- Print the list of presidents, 2- Ask questions a president's number, or 3- Ask a question about a president's quote.
		std::string promptStrPtr = "\nPlease enter your choice 1 to 3 (-1 to exit): ";
		std::string promptWrongStrPtr = "Invalid Choice. Please try again.";

		choice = Utilities::getIntInputValidate(&promptStrPtr, &promptWrongStrPtr);
		switch (choice) {
		case 1: // Print the list of presidents
			std::system("CLS");
			std::cout << "\n" << pd.printPresidents() << "\n";
			continueLooping = true;
			break;
		case 2: // Play about the president's number, correct or incorrect
			std::system("CLS");
			pd.askPresidentQuestion(questionIsTrue, questionStr, correctAnswer);
			std::cout << questionStr;
			std::cin >> answer;
			if ((((answer == "Y") || (answer == "y")) && questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && !questionIsTrue))
			{
				correctAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is correct! You certainly know your history!\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			else if ((((answer == "Y") || (answer == "y")) && !questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && questionIsTrue))			
			{
				wrongAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is wrong! " << correctAnswer <<"\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			continueLooping = true;
			break;
		case 3: // Play about a president quote, real or fake
			std::system("CLS");
			pd.getPresidentQuote(questionIsTrue, questionStr, correctAnswer);
			std::cout << questionStr << " (Y/N): ";
			std::cin >> answer;
			if ((((answer == "Y") || (answer == "y")) && questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && !questionIsTrue))
			{
				correctAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is correct! You certainly know your history!\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			else if ((((answer == "Y") || (answer == "y")) && !questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && questionIsTrue))
			{
				wrongAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is wrong! " << correctAnswer << "\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			continueLooping = true;
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