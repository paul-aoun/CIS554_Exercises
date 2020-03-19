//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/14/2020										//
//													//
// This is the header file for the base class Game.	//
// It declares the functions needed to play			//
// a game.											//
//////////////////////////////////////////////////////
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "GameHelper.h"
#include "GameComponent.h"

// Base game class holding all the game's values needed for 
// to play.
class Game : public GameHelper {

protected:
	//Vector to store the components for the game
	std::vector <GameComponent*> gameComponents;

public:
	virtual void initializeComponents(); // Initialize game components
	virtual const std::string printComponents(); // Prepare a string in a table format with all the components of a game
	virtual void playGame(); //Function to play the game 
	virtual const std::vector <GameComponent*>& getComponents() const; // Return the vector of a game's components
};

#endif