//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// Exercise 5.1										//
//													//
// 2/1/2020											//
//												    //
// This is the modified TimeDiff header file		//
// declaring the required functions: ValidateTime 	//
// and SecondsSinceNoon. It passes the parameters 	//
// by reference.									//
//////////////////////////////////////////////////////
class TimeDiff
{
private:
	bool ValidateTime(int &, int &, int &);

public:
	int SecondsSinceNoon(int &, int &, int &);

};
