//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/19/2020										//
//													//
// This is the President class file.				//
// It defines the functions needed to manager		//
// the president objects.							//
//////////////////////////////////////////////////////
#include <string>
#include "President.h"

// Set the President name.
void President::setName(std::string aName) {
	name = aName;
}

// Set the President order.
void President::setOrder(int anOrder) {
	order = anOrder;
}

// Set the President random order for the trivia games.
void President::setRandomOrder(int aRandomOrder) {
	randomOrder = aRandomOrder;
}

// Set the President guessed order by the user.
void President::setGuessedOrder(int aGuessedOrder) {
	guessedOrder = aGuessedOrder;
}

// Get the President name.
const std::string President::getName() const {
	return name;
}

// Get the President order.
const int President::getOrder() const {
	return order;
}

// Get the President random order for the trivia games.
const int President::getRandomOrder() const
{
	return randomOrder;
}

// Get the President guessed order by the user.
const int President::getGuessedOrder() const{
	return guessedOrder;
}