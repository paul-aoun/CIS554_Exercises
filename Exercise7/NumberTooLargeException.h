// Fig 17.1 (modified): NumberTooLargeException.h
// Class NumberTooLargeException definition.
#include <stdexcept> // stdexcept header contains runtime_error

// NumberTooLargeException objects should be thrown by functions
// upon detecting a result greater than MAX_NUMBER
class NumberTooLargeException : public std::runtime_error {

public:
	// public constant to set the max number at which
	// the exception will be thrown.
	static const unsigned int MAX_NUMBER{ 1000000 };

	// constructor specifices default error message
	NumberTooLargeException()
		: std::runtime_error{ "number is too large" } {}
};
