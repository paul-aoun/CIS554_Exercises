//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/18/2020										//
//													//
// This is the file for the helper class GameHelper.//
// It defines the modifier functions needed to		//
// manage the name of a game.						//
//////////////////////////////////////////////////////
#include <string>
#include "GameHelper.h"

// Function to set the name
const void GameHelper::setName(std::string name) {
	GameHelper::name = name;
}

// Function to get the name
const std::string GameHelper::getName() const
{
	return name;
}