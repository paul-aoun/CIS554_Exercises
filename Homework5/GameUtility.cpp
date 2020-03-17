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