//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #3 -  Exercise 5.16 p206						//
//													//
// 2/6/2020											//
//													//
// This is the header file for the BarChart class.	//
// It declares the functions to set up the bar chart//
// and display it.									//
//////////////////////////////////////////////////////
#include <array>

static const std::array <std::string, 5> numbersOrders = { "first", "second", "third", "fourth", "fifth" };
static const enum class ChartDirection { Vertical, Horizontal };
static const int maxNumberValue = 30; //Maximum allowed value per input number
static const int maxNumbers = 5; //Maximmum number of allowed input numbers

class BarChart
{	
private:
	std::array <int, 5> numbers;

public:	
	
	//Setter function for the bar chart numbers.
	void setNumbers(std::array <int, 5> nums);

	//Getter function for the bar chart numbers.
	std::array <int, 5> getNumbers();

	//Function to prepare the chart. It uses enum class to give a choice to the user
	//for plotting the chart horizontally or vertically.
	std::string plotBarChart(ChartDirection direction);

};

