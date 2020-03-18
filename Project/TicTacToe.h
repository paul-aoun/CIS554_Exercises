//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/15/2020										//
//													//
// This is the header file for the TicTacToeclass.	//
// It declares the functions needed to play			//
// a game.											//
//////////////////////////////////////////////////////
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <vector>
#include "Game.h"
#include "GameComponent.h"

// Base game class holding all the game's values needed for 
// to play.
class TicTacToe : public Game {

private:
	std::array <std::string, 10> boxesValues{ " ",  " ",  " ",  " ",  " ",  " ",  " ",  " ",  " ",  " " }; //hold the players choices
	int numberOfGuesses{ 1 };

	int playerWins() const;

public:
	virtual void initializeComponents(); // Initialize game components
	virtual const std::string printComponents() const; // Prepare a string in a table format with all the components of a game
	virtual void playGame();
	virtual const std::vector <GameComponent*>& getComponents() const; // Return the vector of a game's components
	void setBoxValue(int, std::string);
	std::string getBoxValue(int);
};

#endif