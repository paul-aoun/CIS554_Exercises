//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Final Project - Inheritance and Polymorphism		//
//													//
// 3/18/2020										//
//												    //
// This is the driver file for the games.			//
// It engages the users with the 2 available games:	//
// Tic-Tac-Toe and President Trivia game.			//
// It uses polymorphism to call either of the two	//
// games and keeps looping between the two until	//
// the user chooses to exit.						//
/////////////////////////////////////////////////////

// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <string>
#include "Utilities.h"
#include "PresidentsDay.h"
#include "TicTacToe.h"

int main()
{
	//Used to capture player's choice
	int choice{ 0 };

	//Control the master loop.
	bool continueLooping{ true };
	
	//Output prompts for interacting with the players
	std::string promptString{ "Please choose your game:\n (1): Presidents' Trivia\n (2): Tic-Tac-Toe\n (3): Exit \nYour choice: " };
	std::string invalidString{ "Invalid Choice. Please try again." };

	
	//Loop until the user enters 3 to exit the program
	while (choice != 3)
	{

		std::cout << "Welcome to Game CIS 554-M401 Games! \n\n";
		PresidentsDay pd;
		TicTacToe ttt;

		//Vector containing the derived games available as the base class objects
		std::vector <Game*> games{ &pd, &ttt };

		//Get user input
		choice = Utilities::getIntInputValidate(&promptString, &invalidString);

		//Select which game to play based on the player's choice
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
