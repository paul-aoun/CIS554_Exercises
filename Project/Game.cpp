//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/14/2020										//
//													//
// This is the file for the abstract base class Game//
// It defines the modifier functions needed to		//
// initialize a game.								//
//////////////////////////////////////////////////////
#include <string>
#include "Game.h"

void Game::initializeComponents()
{
}

const std::string Game::printComponents() const
{
	return std::string();
}

void Game::playGame()
{
}

// Returns the vector of presidents
const std::vector<GameComponent*>& Game::getComponents() const
{
	return gameComponents;
}


