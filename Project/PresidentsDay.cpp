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
#include <array>
#include <tuple>
#include <iostream>
#include "Utilities.h"
#include "PresidentsDay.h"

// Function to initialize the presidents' vector
void PresidentsDay::initializeComponents() {
	int presidentCounter{ 0 };
	std::vector<int> randomNumbers;
	
	Utilities::uniqueRandomNumbersGenerator(0, presidentsOrderedNames.size()-1, presidentsOrderedNames.size(), randomNumbers);

	// Loop to instantiate the presidents objects and store them in the presidents vector.
	for (std::string presidentName : presidentsOrderedNames) {
		President* p = new President();
		(*p).setName(presidentName);
		(*p).setOrder(presidentCounter +1);
		(*p).setRandomOrder(randomNumbers.at(presidentCounter++));
		gameComponents.push_back(p);
	}
}

// Constructor to call the initialization function.
PresidentsDay::PresidentsDay() {
	initializeComponents();
}


// Prepare a string in a table format with all the presidents
const std::string PresidentsDay::printComponents() const
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
	
	// Prepare the presidents rows using range based for loop.
	for (GameComponent* c : gameComponents) {
		President* p = dynamic_cast<President*>(c);
		output << std::setw(25) << (*p).getName() << std::setw(5) << (*p).getOrder() + 1  << "\n";
	}
	return output.str();
}

// Prepare a questions with a correct and incorrect answers from the list and return by reference
void PresidentsDay::askPresidentQuestion(bool& questionIsTrue, std::string& questionStr, std::string& correctAnswer) const
{
	int num{ 0 };
	Utilities::randomNumbersGenerator(0, gameComponents.size() -1, num);
	
	GameComponent* c = gameComponents.at(num);
	President* p = dynamic_cast<President*>(c);

	std::ostringstream question, answer;

	// Randomly chose a question style, some correct and some incorrect answers
	Utilities::randomNumbersGenerator(0, 3, num);
	switch (num) {
	case 0:
		question << "President " << (*p).getName() << " was number " << (*p).getRandomOrder() << "? (Y/N): ";
		if ((*p).getOrder() + 1 == (*p).getRandomOrder()) {
			questionIsTrue = true;
		}
		else {
			questionIsTrue = false;
		}
		break;
	case 1:
		question << "President " << (*p).getName() << " was number " << (*p).getOrder() +1 << "? (Y/N): ";
		questionIsTrue = true;
		break;
	case 2:
		question << "President number " << (*p).getRandomOrder() << " was " << (*p).getName() << " ? (Y/N): ";
		if ((*p).getOrder() + 1 == (*p).getRandomOrder()) {
			questionIsTrue = true;
		}
		else {
			questionIsTrue = false;
		}
		break;
	case 3:
		question << "President number " << (*p).getOrder() +1 << " was " << (*p).getName() << " ? (Y/N): ";
		questionIsTrue = true;
		break;
	}
	
	questionStr = question.str();
	
	answer << "President " << (*p).getName() << " was number " << (*p).getOrder() +1 << "!";
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

void PresidentsDay::playGame()
{
	//PresidentsDay pd;

	std::system("CLS");
	//Loop until the user enters an integer for difficulty level or exists
	while (continueLooping)
	{
		// Prints the welcome message and options for the player.
		std::cout << welcomePrompts[0];
		std::cout << welcomePrompts[1];
		std::cout << welcomePrompts[2];
		std::cout << welcomePrompts[3];

		// Depending on the user's choice, it will play one of the 3 available options:
		// 1- Print the list of presidents, 2- Ask questions a president's number, or 3- Ask a question about a president's quote.
		std::string promptStrPtr = "\nPlease enter your choice 1 to 3 (-1 to exit): ";
		std::string promptWrongStrPtr = "Invalid Choice. Please try again.";

		choice = Utilities::getIntInputValidate(&promptStrPtr, &promptWrongStrPtr);
		switch (choice) {
		case 1: // Print the list of presidents
			std::system("CLS");
			std::cout << "\n" << printComponents() << "\n";
			continueLooping = true;
			break;
		case 2: // Play about the president's number, correct or incorrect
			std::system("CLS");
			askPresidentQuestion(questionIsTrue, questionStr, correctAnswer);
			std::cout << questionStr;
			std::cin >> answer;
			if ((((answer == "Y") || (answer == "y")) && questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && !questionIsTrue))
			{
				correctAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is correct! You certainly know your history!\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			else if ((((answer == "Y") || (answer == "y")) && !questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && questionIsTrue))
			{
				wrongAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is wrong! " << correctAnswer << "\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			continueLooping = true;
			break;
		case 3: // Play about a president quote, real or fake
			std::system("CLS");
			getPresidentQuote(questionIsTrue, questionStr, correctAnswer);
			std::cout << questionStr << " (Y/N): ";
			std::cin >> answer;
			if ((((answer == "Y") || (answer == "y")) && questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && !questionIsTrue))
			{
				correctAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is correct! You certainly know your history!\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			else if ((((answer == "Y") || (answer == "y")) && !questionIsTrue) ||
				(((answer == "N") || (answer == "n")) && questionIsTrue))
			{
				wrongAnswers++;
				score = (correctAnswers * 100.0 / (static_cast <double>(correctAnswers) + static_cast <double>(wrongAnswers)));
				std::cout << "Your answer is wrong! " << correctAnswer << "\n";
				std::cout << "Your score so far is: " << std::fixed << std::setprecision(2) << score << "%\n\n";
			}
			continueLooping = true;
			break;
		case -1:
			continueLooping = false;
			break;
		default:
			continueLooping = true;
			break;
		}
	}
}