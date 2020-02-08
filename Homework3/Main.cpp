//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #3 -  Exercise 5.16 p206						//
//													//
// 2/6/2020											//
//												    //
// This is the driver file for the BarChart class.	//
// A BarChart object store the parameters			//
// of the chart.								 	//
// This files will prompt the users for the numbers //
// and plots the chart, either vertically or		//
// horizontally.									//
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "BarChart.h"

int main()
{
	bool continueLooping{ true }, continueInnerLooping{ true };

	const size_t arraySize = 5;
	std::array <int, arraySize> numbers = { 0 };

	BarChart barChart;
	std::string chart{ "" };
	char direction{ ' ' };

	//Will loop until the user exits by entering -1 for any input value. 
	//It will validate all inputs and then returns the balance, if below the credit limit. Or, the statement and the balance, if above the credit limit. 
	std::cout << "Enter " + std::to_string(maxNumbers) + " numbers between 1 and 30 (-1 to stop): \n";

	int numbersEntered{ 0 };

	//Input the maxNumber numbers between 1 and 30
	while (continueLooping)
	{
		do
		{ //Gets and validutes the input from the user.
			numbers[numbersEntered] = Utilities::getIntInputValidate("Enter " + numbersOrders[numbersEntered] + " (or -1 to quit): ", numbersOrders[numbersEntered] + " Number");

			if (numbers[numbersEntered] == -1)
			{
				continueLooping = false;
				break;
			}
			else if (numbers[numbersEntered] > 30)
			{
				continueLooping = true;
				std::cout << "Number must be between 1 and 30. \n";
			}
			else
			{
				continueLooping = true;
				break;
			}

		} while (true);
		
		if ((numbersEntered++ == 4) && (continueLooping = true))
		{ //Plots the chart vertically or horizontally depending on user choice.
			do
			{
				barChart.setNumbers(numbers);

				std::cout << "Do you want to display the chart vertically or horizontally (V/H, -1 to exit)? ";
				std::cin >> direction;

				if ((direction == 'V') || (direction == 'v')) 
				{
					chart = barChart.plotBarChart(ChartDirection::Vertical);
					continueInnerLooping = false;
				}
				else if ((direction == 'H') || (direction == 'h'))
				{
					chart = barChart.plotBarChart(ChartDirection::Horizontal);
					continueInnerLooping = false;
				}
				else if (direction == '-1')
				{
					continueInnerLooping = false;
				} 
				else
				{
					std::cout << "Invalid choice. ";
				}

				std::cout << chart + "\n";
					numbersEntered = 0;
			} while (continueInnerLooping);
		}
	}

	
};
