#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include "Utilities.h"
#include "PresidentsDay.h"

void PresidentsDay::initializePresidents() {
	int presidentCounter{ 0 };
	std::vector<int> randomNumbers;
	
	Utilities::uniqueRandomNumbersGenerator(0, presidentsOrderedNames.size()-1, presidentsOrderedNames.size(), randomNumbers);

	for (std::string presidentName : presidentsOrderedNames) {
		President p;
		p.setName(presidentName);
		p.setOrder(presidentCounter);
		p.setRandomOrder(randomNumbers.at(presidentCounter++));
		presidents.push_back(p);
	}
}

PresidentsDay::PresidentsDay() {
	initializePresidents();
}

const std::vector<President>& PresidentsDay::getPresidents() const
{
	return presidents;
}

const std::string PresidentsDay::printPresidents() const
{
	std::ostringstream output;

	output << std::setw(18) << "President Name"<< std::setw(29) << "President Number \n" ;
	for (int i = 0; i < 3; i++) {
		output << " ";
	}
	for (int i = 4; i < 45; i++) {
		output << "_";
	}
	output << "\n";

	for (President p : presidents) {
		output << std::setw(25) << p.getName() << std::setw(5) << p.getOrder() + 1  << "\n";
	}
	return output.str();
}
void PresidentsDay::askPresidentQuestion(bool& questionIsTrue, std::string& questionStr, std::string& correctAnswer) const
{
	int num{ 0 };
	Utilities::randomNumbersGenerator(0, presidents.size() -1, num);
	President p = presidents.at(num);
	std::ostringstream question, answer;

	Utilities::randomNumbersGenerator(0, 3, num);
	switch (num) {
	case 0:
		question << "President " << p.getName() << " was number " << p.getRandomOrder() << "? (Y/N): ";
		if (p.getOrder() + 1 == p.getRandomOrder()) {
			questionIsTrue = true;
		}
		else {
			questionIsTrue = false;
		}
		break;
	case 1:
		question << "President " << p.getName() << " was number " << p.getOrder() +1 << "? (Y/N): ";
		questionIsTrue = true;
		break;
	case 2:
		question << "President number " << p.getRandomOrder() << " was " << p.getName() << " ? (Y/N): ";
		if (p.getOrder() + 1 == p.getRandomOrder()) {
			questionIsTrue = true;
		}
		else {
			questionIsTrue = false;
		}
		break;
	case 3:
		question << "President number " << p.getOrder() +1 << " was " << p.getName() << " ? (Y/N): ";
		questionIsTrue = true;
		break;
	}
	
	questionStr = question.str();
	
	answer << "President " << p.getName() << " was number " << p.getOrder() +1 << "!";
	correctAnswer = answer.str();


}
/*
void PresidentsDay::guessPresidentsOrder(std::vector<int>& presidentsOrderGuesses, std::vector<std::string>& remainingPresidentstoOrder) const
{
	for (int presidentNumber : presidentsOrderGuesses) {

	}
}
*/