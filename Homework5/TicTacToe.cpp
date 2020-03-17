//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/15/2020										//
//													//
// This is the file for the TicTacToe class.		//
// It defines the functions needed to				//
// play the game.									//
//////////////////////////////////////////////////////

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <array>
#include <tuple>
#include <iostream>
#include <Windows.h>
#include "TicTacToe.h"
#include "Utilities.h"

//Check if one of the players won based on the Tic-Tac-Toe rules.
//Return 1 if player 1 wins, 2, if player 2 wins, and 0, if neither wins
int TicTacToe::playerWins() const
{
	//Check if there is a horizontal win
	for (int i = 0; i <= 6; i += 3) {
		if ((boxesValues[1 + i] == "X") && (boxesValues[2 + i] == "X") && (boxesValues[3 + i] == "X")) {
			return 1;
		}
		else if ((boxesValues[1 + i] == "O") && (boxesValues[2 + i] == "O") && (boxesValues[3 + i] == "O"))
		{
			return 2;
		}
	}

	//Check if there is a vertical win
	for (int i = 0; i < 3; i++) {
		if ((boxesValues[1 + i] == "X") && (boxesValues[4 + i] == "X") && (boxesValues[7 + i] == "X")) {
			return 1;
		}
		else if ((boxesValues[1 + i] == "O") && (boxesValues[4 + i] == "O") && (boxesValues[7 + i] == "O")) {
			return 2;
		}
	}

	//check if there is a diagonal (/) win
	if ((boxesValues[1] == "X") && (boxesValues[5] == "X") && (boxesValues[9] == "X")) {
		return 1;
	}
	else if ((boxesValues[1] == "O") && (boxesValues[5] == "O") && (boxesValues[9] == "O")) {
		return 2;
	}

	//check if there is a diagonal (\) win
	if ((boxesValues[3] == "X") && (boxesValues[5] == "X") && (boxesValues[7] == "X")) {
		return 1;
	}
	else if ((boxesValues[3] == "O") && (boxesValues[5] == "O") && (boxesValues[7] == "O")) {
		return 2;
	}

	return 0;
}

void TicTacToe::initializeComponents()
{
}

// Prepare a string in a table format with all the TicTacToe information
const std::string TicTacToe::printComponents() const {

	std::ostringstream output;
	int width{ 30 };
	int height{ 18 };
	int boxWidth{ 10 };
	int boxHeight{ 6 };
	int boxCounter{ 1 };
	int rowCounter{ 0 };

	bool boxIncrementedFirst{ false }, boxIncrementedSecond{ false };
	std::vector <std::string> rows;
	std::string row{ "" }, lineRow{ "" };

	output << std::setw(18) << "Tic-Tac-Toe Game" << std::setw(29) << " Game 1 \n";

	for (int i = 0; i <= width + 8; i++)
		lineRow += "=";

	for (int i = 0; i <= height; i++) {
		if ((i % boxHeight) != 0) {
			for (int j = 0; j <= width; j++) {
				if (((j % boxWidth) == 0) && (j != 0) && (j != width)) {
					row += std::to_string(boxCounter++ + rowCounter);
					row += "|";
				}
				else {
					row += boxesValues[boxCounter + rowCounter];
				}
			}
			row += std::to_string(boxCounter + rowCounter) + "|";
			output << row << "\n";
			row = "";
			boxCounter = 1;
		}
		else if ((i != 0) && (i != height)) {
			output << lineRow << "\n";
			boxCounter = 1;
			rowCounter += 3;
		}

	}



	/*CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	*/
	std::cout << "Font: Consolas, Size: 24\n";
	return output.str();
}

void TicTacToe::playGame()
{
	int choice{ 0 };
	bool continueLooping{ true };
	std::string promptStrPtr{ "" };
	std::string promptWrongStrPtr = "Invalid Choice. Please try again.";
	std::cout << printComponents() << "\n";
	//Loop until one of the players wins or they reach the maximun number of guess. 
	while ((playerWins() == 0) && (numberOfGuesses <= 9)) {
		
		continueLooping = true;
		while ((continueLooping) && (playerWins() == 0)) {
			promptStrPtr = "\nPlayer 1 enter your box choice (-1 to exit): ";
			choice = Utilities::getIntInputValidate(&promptStrPtr, &promptWrongStrPtr);
			if ((choice >= 1) && (choice <= 9) && (getBoxValue(choice) == " ")) {
				setBoxValue(choice, "X");
				numberOfGuesses++;
				std::cout << printComponents() << "\n";
				continueLooping = false;
			}
			else {
				std::cout << promptWrongStrPtr << "\n";
			}
		}

		continueLooping = true;
		while ((continueLooping) && (playerWins() == 0)) {
			promptStrPtr = "\nPlayer 2 enter your box choice (-1 to exit): ";
			choice = Utilities::getIntInputValidate(&promptStrPtr, &promptWrongStrPtr);
			if ((choice >= 1) && (choice <= 9) && (getBoxValue(choice) == " ")) {
				setBoxValue(choice, "O");
				numberOfGuesses++;
				std::cout << printComponents() << "\n";
				continueLooping = false;
			}
			else {
				std::cout << promptWrongStrPtr << "\n";
			}
		}
	}

	choice = playerWins();
	if (choice > 0) {
		std::cout << "Congratulations player " << choice << "! You win!" << "\n";
	}
}


const std::vector<GameComponent*>& TicTacToe::getComponents() const
{
	return gameComponents;
}

//Set the box value based on the player's choice. It checks that the value is either "X" or "O" and that the box number
//is within range. Otherwise no change.
void TicTacToe::setBoxValue(int boxNumber, std::string value)
{
	if ((((value == "X") || (value == "O"))) && ((boxNumber > 0) && (boxNumber < 10)))
		boxesValues[boxNumber] = value;
}
//Return the box value requested. Return "-1", if the box number is not between 1 and 9.
std::string TicTacToe::getBoxValue(int boxNumber)
{
	if ((boxNumber > 0) && (boxNumber < 10)) {
		return boxesValues[boxNumber];
	}
	else {
		return "-1";
	}

}
