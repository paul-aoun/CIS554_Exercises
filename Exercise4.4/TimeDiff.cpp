//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 4.4										//
//													//
// 1/27/2020										//
//												    //
// This is the TimeDiff class, defining the       	//
// required functions: ValidateTime and         	//
// SecondsSinceNoon.                            	//
//////////////////////////////////////////////////////
#include <iostream>
#include "TimeDiff.h"

//Function to validate that the time values given are valid.
//Will return true if they are, false otherwise.
bool TimeDiff::ValidateTime(int hour, int minute, int second)
{
	if ((hour < 0) || (hour > 23) || (minute < 0) || (minute > 59) ||
		 (second < 0) || (second > 59))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Function to calculate the seconds elapsed since noon based on the time
//entered by the user.
int TimeDiff::SecondsSinceNoon(int hour, int minute, int second)
{
	int hoursElapsedSinceNoon{ 0 };

	if (ValidateTime (hour, minute, second)) {

		if (hour >= 12) 
		{
			hoursElapsedSinceNoon = hour - 12;
		}
		else
		{
			hoursElapsedSinceNoon = hour + 12;
		}

		return hoursElapsedSinceNoon * 3600 + minute * 60 + second;
	}
	else
	{
		return -1;
	}
}
