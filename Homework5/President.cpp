#include <vector>
#include <string>
#include "President.h"

void President::setName(std::string aName) {
	name = aName;
}

void President::setOrder(int anOrder) {
	order = anOrder;
}

void President::setRandomOrder(int aRandomOrder) {
	randomOrder = aRandomOrder;
}

void President::setGuessedOrder(int aGuessedOrder) {
	guessedOrder = aGuessedOrder;
}

const std::string President::getName() const {
	return name;
}

const int President::getOrder() const {
	return order;
}

const int President::getRandomOrder() const
{
	return randomOrder;
}

const int President::getGuessedOrder() const{
	return guessedOrder;
}