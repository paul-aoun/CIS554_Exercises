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
#include "TicTacToe.h"
#include "Main.h"

int main()
{
	
	int choice{ 0 };
	bool continueLooping{ true };
	//std::string dummy{ "" }; //dummy variable to pause the screen for the players to read the game result
	
	std::string promptString{ "Please choose your game:\n (1): Presidents' Trivia\n (2): Tic-Tac-Toe\n (3): Exit \nYour choice: " };
	std::string invalidString{ "Invalid Choice. Please try again." };

	
	//Loop until the user enters an integer for difficulty level or exists
	while (choice != 3)
	{
		//std::system("CLS");
		std::cout << "Welcome to Game CIS 554-M401 Games! \n\n";
		PresidentsDay pd;
		TicTacToe ttt;

		std::vector <Game*> games{ &pd, &ttt };

		choice = Utilities::getIntInputValidate(&promptString, &invalidString);
		//std::system("CLS");

		if ((choice == 1) || (choice == 2))
		{
			//Polymorphic playing
			(*games.at(choice -1)).playGame();
			std::cout << "\n\n";
			//std::cin >> dummy;
		}
		else if (choice != 3) {
			std::cout << invalidString << "\n";
		}
	}
}
