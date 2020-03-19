//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/15/2020										//
//													//
// This is the header file for the TicTacToe class.	//
// It declares the functions needed to play			//
// a game of TicTacToe.								//
//////////////////////////////////////////////////////
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <vector>
#include "Game.h"
#include "GameComponent.h"

// Base game class holding all the game's values needed 
// to play Tic-Tac-Toe.
class TicTacToe : public Game {

private:
	//Hold "X" or "O" values for each of the nine boxes based on the players' choices. Size is 10 since the counter starts at 1.
	std::array <std::string, 10> boxesValues{ " ",  " ",  " ",  " ",  " ",  " ",  " ",  " ",  " ",  " " }; 
	
	//Used to count how many time the players guessed
	int numberOfGuesses{ 1 };
	
	//Variables used to draw the Tic-Tac-Toe play matrix
	int width{ 30 };
	int height{ 18 };
	int boxWidth{ 10 };
	int boxHeight{ 6 };
	int boxCounter{ 1 };
	int rowCounter{ 0 };

	int playerWins() const;

public:
	// Initialize game components
	virtual void initializeComponents(); 
	
	// Prepare a string in a table format with all the components of a game
	virtual const std::string printComponents(); 

	//Game play function with all the Tic-Tac-Toe logic
	virtual void playGame();

	// Return the vector of a game's components
	virtual const std::vector <GameComponent*>& getComponents() const; 
	
	//Setter and Getter functions for the Tic-Tac-Toe boxes
	void setBoxValue(int, std::string);
	std::string getBoxValue(int);
};

#endif