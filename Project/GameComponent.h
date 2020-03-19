//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/14/2020										//
//													//
// This is the header file for the base class 		//
// GameComponent. It declares the functions needed  //
// for the components of a game.					//
/////////////////////////////////////////////////////

#ifndef GAMECOMPONENT_H
#define GAMECOMPONENT_H

#include <string>
#include "GameHelper.h"


class GameComponent : public GameHelper {

public:
	//Pure virtual function to print a Game component
	virtual std::string toString() const = 0; 
};

#endif