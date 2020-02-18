#include <string>
#include <vector>
#include "President.h"

#ifndef PRESIDENTSDAY_H
#define PRESIDENTSDAY_H

//USE const as much as possible

class PresidentsDay {


private:
	std::vector <std::string> presidentsOrderedNames{ "George Washington", "John Adams","Thomas Jefferson", "James Madison", "Jamse Monroe", "John Quincy Adams",
		"Andrew Jackson", "Martin Van Buren", "William Henry Harrison", "John Tyler", "Jamse K. Polk", "Zachary Taylor", "Millard Fillmore", "Franklin Pierce", 
		"James Buchanan","Abraham Linclon", "Andrew Johnson", "Ulysses S. Grant", "Rutherford B. Hayes", "James A. Garfield", "Chester A.Arthur", "Grover Cleveland", 
		"Benjamin Harrison", "Grover Cleveland", "William McKinley", "Theodore Roosevelt", "William Howard Taft", "Woodrow Wilson", "Warren G. Harding", "Calvin Coolidge", 
		"Herbert Hoover", "Franklin D. Roosevelt", "Harry S. Truman", "Dwight D. Eisenhower", "John F. Kennedy", "Lyndon B. Johnson", "Richard Nixon", "Gerlard Ford", 
		"Jimmy Carter", "Ronald Reagan", "George H. W. Bush", "Bill Clinton", "George W. Bush", "Barack Obama", "Donald Trump"};
	std::vector <President> presidents;
	void initializePresidents();

public:
	PresidentsDay(); //constructor
	const std::vector <President>& getPresidents() const;
	const std::string printPresidents() const;
};


#endif PRESIDENTSDAY_H
/*
President day quizz:
1- List of presidents from original to Trump
2- True false facts about each one
3-	achievements
4- other things related to presidents 
5- american flag with stars
*/