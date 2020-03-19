//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/14/2020										//
//													//
// This is the header file for the helper class 	//
// GameHelper. It declares the functions common	    //
// for the objects of a game.						//
//////////////////////////////////////////////////////

#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include <string>

class GameHelper {

private:
	std::string name{ "" };

public:
	//Getter and Setter functions for the Game objects
	virtual const void setName(std::string);
	virtual const std::string getName() const;
};

#endif
