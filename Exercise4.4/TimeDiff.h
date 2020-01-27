//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 4.4										//
//													//
// 1/27/2020										//
//												    //
// This is the TimeDiff header file	declaring		//
// required functions: ValidateTime and         	//
// SecondsSinceNoon.                            	//
//////////////////////////////////////////////////////
class TimeDiff
{
private:
	bool ValidateTime(int, int, int);

public:
	int SecondsSinceNoon(int, int, int);

};
