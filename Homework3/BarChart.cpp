//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #3 -  Exercise 5.16 p206						//
//													//
// 2/6/2020											//
//													//
// This is the BarChart class. It defines the		//
//functions to set up the bar chart and displays it.//									//
//////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "BarChart.h"

//Setter function for the bar chart numbers.
void BarChart::setNumbers(std::array <int, 5> nums)
{
	numbers = nums;
}

//Getter function for the bar chart numbers.
std::array <int, 5> BarChart::getNumbers()
{
	return numbers;
}

//Function to prepare the chart. It uses enum class to give a choice to the user
//for plotting the chart horizontally or vertically.
std::string BarChart::plotBarChart(ChartDirection direction)
{

	std::string output{ "" };
	std::string stars{ "" };
	bool starFound{ false };

	//Prepare horizontal chart
	if (direction == ChartDirection::Horizontal) {
		for (int i = 0; i < numbers.size(); i++)
		{
			stars = "";
			for (int j = 0; j < numbers[i]; j++)
			{
				stars += "*";
			}
			
			if (numbers[i] < 10) //single digit number, adding space to beautify output
			{
				output += std::to_string(numbers[i]) + " : " + stars + "\n";
			}
			else
			{
				output += std::to_string(numbers[i]) + ": " + stars + "\n";
			}
		}
	}
	else if (direction == ChartDirection::Vertical) //Prepare vertical chart
	{
		std::array <std::string, maxNumberValue + 1> rows;
		std::array <int, maxNumberValue + 1> starsAdded;

		//Intialize array to avoid undefined results
		for (int i = 1; i <= numbers.size(); i++)
		{
			starsAdded[i] = 0;
		}

		//Intialize array to avoid undefined results
		for (int i = 1; i <= maxNumberValue; i++)
		{
			rows[i] = "";
		}

		//Prepare the x-axis of the chart based on the input numbers
		for (int i = 0; i < numbers.size(); i++)
		{
			rows[0] += " " + std::to_string(numbers[i]) + " ";
		}
		rows[0] += "\n";

		//Prepare the stars rows, for 1 to the number of entered digits (set up in BarChart.h)
		for (int i = 0; i < numbers.size(); i++)
		{
			for (int j = 1; j <= numbers[i]; j++)
			{
				rows[j] += " * ";
			}

			//Add spaces for the remaining columns
			for (int j = numbers[i] + 1; j <= maxNumberValue; j++)
			{
				rows[j] += "   ";
			}
		}
		
		//Prepare final ouput and check for empty row (no stars) to stop
		for (int i = maxNumberValue; i > 0; i--)
		{
			for (int j = 0; j < rows[i].size(); j++)
			{
				if (rows[i][j] == '*')
				{
					output += rows[i] + "\n";
					break;
				}
			}
			starFound = false;
		}
		output += rows[0];
	}
	return output;
}