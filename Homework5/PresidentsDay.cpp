//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/19/2020										//
//													//
// This is the file for the PresidentDay class.		//
// It defines the functions needed to				//
// play the trivia games about the presidents.		//
//////////////////////////////////////////////////////
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <tuple>
#include <iostream>
#include "Utilities.h"
#include "PresidentsDay.h"

// Function to initialize the presidents' vector
void PresidentsDay::initializePresidents() {
	int presidentCounter{ 0 };
	std::vector<int> randomNumbers;
	
	Utilities::uniqueRandomNumbersGenerator(0, presidentsOrderedNames.size()-1, presidentsOrderedNames.size(), randomNumbers);

	// Loop to instantiate the presidents objects and store them in the presidents vector.
	for (std::string presidentName : presidentsOrderedNames) {
		President p;
		p.setName(presidentName);
		p.setOrder(presidentCounter +1);
		p.setRandomOrder(randomNumbers.at(presidentCounter++));
		presidents.push_back(p);
	}
}

// Constructor to call the initialization function.
PresidentsDay::PresidentsDay() {
	initializePresidents();
}

// Returns the vector of presidents
const std::vector<President>& PresidentsDay::getPresidents() const
{
	return presidents;
}

// Prepare a string in a table format with all the presidents
const std::string PresidentsDay::printPresidents() const
{
	std::ostringstream output;

	output << std::setw(18) << "President Name"<< std::setw(29) << "President Number \n" ;
	
	// Format output
	for (int i = 0; i < 3; i++) {
		output << " ";
	}
	for (int i = 4; i < 45; i++) {
		output << "_";
	}
	output << "\n";

	// Prepare the presidents rows
	for (President p : presidents) {
		output << std::setw(25) << p.getName() << std::setw(5) << p.getOrder() + 1  << "\n";
	}
	return output.str();
}

// Prepare a questions with a correct and incorrect answers from the list and return by reference
void PresidentsDay::askPresidentQuestion(bool& questionIsTrue, std::string& questionStr, std::string& correctAnswer) const
{
	int num{ 0 };
	Utilities::randomNumbersGenerator(0, presidents.size() -1, num);
	President p = presidents.at(num);
	std::ostringstream question, answer;

	// Randomly chose a question style, some correct and some incorrect answers
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

// Prepare a real quote and a fake quote and return by reference.
void PresidentsDay::getPresidentQuote(bool& quoteIsTrue, std::string& quoteStr, std::string& correctQuote) const
{
	
	std::ostringstream quote, fakeQuote;
	int num{ 0 };

	// Get a random number
	Utilities::randomNumbersGenerator(0, presidentsRealQuotes.size() - 1, num);

	// Get a president real quote tuple using the random number
	std::tuple<std::string, std::string> presidentQuoteTuple = presidentsRealQuotes.at(num);
	std::string presidentName = std::get<0>(presidentQuoteTuple);
	std::string presidentQuote = std::get<1>(presidentQuoteTuple);

	// Get a president fake quote tuple using the random number
	presidentQuoteTuple = presidentsFakeQuotes.at(num);
	std::string presidentFakeQuote = std::get<1>(presidentQuoteTuple);

	// Prepare the real and fake quotes
	quote << "President " << presidentName << " said: \"" << presidentQuote << "\"";
	fakeQuote << "President " << presidentName << " said: \"" << presidentFakeQuote << "\"";
	
	// Randomly return the real or fake quote 
	Utilities::randomNumbersGenerator(0, 1, num);
	switch (num) {
	case 0:
		quoteIsTrue = true;
		quoteStr = quote.str();
		correctQuote = quote.str();
		break;
	case 1:
		quoteIsTrue = false;
		quoteStr = fakeQuote.str();
		correctQuote = quote.str();
		break;
	}
}
