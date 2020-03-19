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
#include "UnimplementedException.h"


#include "Game.h"

//Dummy function definition to allow polymorphism for derived classes using Vector
//Will throw runtime exception if not overriden by derived class
void Game::initializeComponents()
{
	throw UnimplementedException{};
}

//Dummy function definition to allow polymorphism for derived classes using Vector
//Will throw runtime exception if not overriden by derived class
const std::string Game::printComponents()
{
	throw UnimplementedException{};
	return std::string(); 
}

//Dummy function definition to allow polymorphism for derived classes using Vector
//Will throw runtime exception if not overriden by derived class
void Game::playGame()
{
	throw UnimplementedException{};
}

//Return the vector of presidents
const std::vector<GameComponent*>& Game::getComponents() const
{
	return gameComponents;
}


