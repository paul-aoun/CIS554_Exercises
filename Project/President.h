//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/19/2020										//
//													//
// This is the header file for the President class.	//
// It declares the functions needed to manager		//
// the president objects.							//
//////////////////////////////////////////////////////
#include <string>
#include "GameComponent.h"

// President class holding all the President's values needed for 
// the trivia games.
class President : public GameComponent {

private:
	int order{ 0 }, randomOrder{ 0 }, guessedOrder{ 0 };

public:
	// Setter functions for the Presidents values.
	void setOrder(int);
	void setRandomOrder(int);
	void setGuessedOrder(int);

	// Getter functions for the Presidents values.
	const int getOrder() const;
	const int getRandomOrder() const;
	const int getGuessedOrder() const;
};
