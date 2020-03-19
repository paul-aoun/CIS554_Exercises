//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 3/18/2020										//
//													//
// This is the class file for the Unimplemented		//
// exception. It is thrown when a derived class		//
// doesn't override a function and that function 	//
// is called.										// 
//////////////////////////////////////////////////////

#include <stdexcept>

//Exception thrown when an unimplemented functions from the base class is called
class UnimplementedException : public std::runtime_error {
public:
	UnimplementedException()
		: std::runtime_error{ "function not implemented." } {};

};
