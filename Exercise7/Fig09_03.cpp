// Fig 9.3: fig09_03.cpp
// Program to test class Time.
// Note: This file must be compiled with Time.cpp
#include <iostream>
#include <stdexcept>
#include "Time.h"
using namespace std;

// display a Time in 24-hour and 12-hour formats
void displayTime(const string& message, const Time& time) {
	cout << message << "\nUniversal time: " << time.toUniversalString()
		<< "\nStandard time: " << time.toStandardString() << "\n\n";
}

int main() {
	Time t, t1; // instantiate object t of class Time
	Time * ptrT = &t;

	t1 = t;

	displayTime("Initial time:", *ptrT); // display t's initial value
	t.setTime(13, 27, 6); // change time
	displayTime("After set time:", *ptrT); // display t's new value

	// attempt to set the time with invalid values
	try {
		ptrT->setTime(99, 99, 99); // all values out of range
	}
	catch (invalid_argument & e) {
		cout << "Exception: " << e.what() << "\n\n";
	}

	//display t's value after attempting to set an invalid time
	displayTime("After attempting to set an invalid time:", *ptrT);
}