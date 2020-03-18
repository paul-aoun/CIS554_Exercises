//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/19/2020										//
//													//
// This is the header file for the PresidentDay 	//
// class. It declares the functions needed to		//
// play the trivia games about the presidents.		//
//////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <tuple>
#include "Game.h"
#include "President.h"

#ifndef PRESIDENTSDAY_H
#define PRESIDENTSDAY_H

class PresidentsDay : public Game {

private:
	//Ordered vector of containing the names of the presidents.
	std::vector <std::string> presidentsOrderedNames{ "George Washington", "John Adams","Thomas Jefferson", "James Madison", "Jamse Monroe", "John Quincy Adams",
		"Andrew Jackson", "Martin Van Buren", "William Henry Harrison", "John Tyler", "Jamse K. Polk", "Zachary Taylor", "Millard Fillmore", "Franklin Pierce",
		"James Buchanan","Abraham Linclon", "Andrew Johnson", "Ulysses S. Grant", "Rutherford B. Hayes", "James A. Garfield", "Chester A.Arthur", "Grover Cleveland",
		"Benjamin Harrison", "Grover Cleveland", "William McKinley", "Theodore Roosevelt", "William Howard Taft", "Woodrow Wilson", "Warren G. Harding", "Calvin Coolidge",
		"Herbert Hoover", "Franklin D. Roosevelt", "Harry S. Truman", "Dwight D. Eisenhower", "John F. Kennedy", "Lyndon B. Johnson", "Richard Nixon", "Gerlard Ford",
		"Jimmy Carter", "Ronald Reagan", "George H. W. Bush", "Bill Clinton", "George W. Bush", "Barack Obama", "Donald Trump" };
	
	//Vector of tuples with each tuple containing the president's name and a real quote. 
	std::vector <std::tuple<std::string, std::string>> presidentsRealQuotes{ std::make_tuple("Abraham Linclon", "I don't like that man. I must get to know him better."),
		std::make_tuple("George Washington", "My first wish is to see this plague of mankind, war, banished from the earth"),
		std::make_tuple("Donald Trump", "No dream is too big.No challenge is too great.Nothing we want for our future is beyond our reach."),
		std::make_tuple("John F. Kennedy", "Change is the law of life. And those who look only to the past or present are certain to miss the future."),
		std::make_tuple("Woodrow Wilson", "One cool judgment is worth a thousand hasty counsels. The thing to do is to supply light and not heat") };
	
	//Vector of tuples with each tuple containing the president's name and a fake quote. 
	std::vector <std::tuple<std::string, std::string>> presidentsFakeQuotes{ std::make_tuple("Abraham Linclon", "I don't like that man. I must stay away from him."),
		std::make_tuple("George Washington", "My third wish is to see this plague of mankind, war, banished from the earth"), 
		std::make_tuple("Donald Trump", "Dream small, talk big, and you will win."),
		std::make_tuple("John F. Kennedy", "Change is the exception. And those who look only to the past or present are certain to miss the future."),
		std::make_tuple("Woodrow Wilson", "One fast judgment is worth a thousand hasty counsels. The thing to do is to apply heat to urgent matters")};


	bool continueLooping{ true };
	int choice{ 0 }; //user choice
	unsigned int correctAnswers{ 0 }, wrongAnswers{ 0 };
	double score{ 0.0 };
	std::string answer{ "" }, questionStr{ "" }, correctAnswer{ "" };
	bool questionIsTrue{ false };
	std::array <std::string, 4> welcomePrompts{ "Welcome to Presidents' Day Trivia! \n\n", "Option 1: Refresh your memory about the United States Presidents to date. \n",
		"Option 2: Questions about the Presidents focusing on their presidency's number. \n", "Option 3: Trivia about the Presidents. \n" };

	// Function to initialize the presidents' vector
	void initializeComponents();
	
public:
	PresidentsDay(); //constructor
	
	virtual const std::string printComponents() const; // Prepare a string in a table format with all the components of a game
	virtual void playGame();

	void askPresidentQuestion(bool&, std::string&, std::string&) const; // Prepare a questions with a correct and incorrect answers from the list and return by reference
	void getPresidentQuote(bool&, std::string&, std::string&) const; // Prepare a real quote and a fake quote and return by reference.
};
#endif PRESIDENTSDAY_H