// Fig 9.2: Time.cpp
// Time class member-function definitions.
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include "Time.h"

using namespace std;


Time::Time() {
	std::cout << "Time constructor called!\n";
}

Time::~Time() {
	std::cout << "Time destructor called!\n";
}
// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
	// validate hour, minute and second
	if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
		hour = h;
		minute = m;
		second = s;
	}
	else {
		throw invalid_argument(
			"hour, minute and/or second was out of range");
	}
}

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
	ostringstream output;
	output << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << setw(2) << second;
	return output.str(); // returns the formatted string
}

// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
	ostringstream output;
	output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< setfill('0') << setw(2) << minute << ":" << setw(2)
		<< second << (hour < 12 ? "AM" : "PM");
	return output.str(); // returns the formatted string
}