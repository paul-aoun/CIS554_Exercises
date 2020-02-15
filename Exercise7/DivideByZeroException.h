// Fig 17.1: DivideByZeroException.h
// Class DivideByZeroException definition.
#include <stdexcept> // stdexcept header contains runtime_error

// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException : public std::runtime_error {
public:
	// constructor specifices default error message
	DivideByZeroException()
		: std::runtime_error{"attempted to divide by zero"} {}
};
