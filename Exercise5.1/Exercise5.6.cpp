// Fig. 7.3: fig07_03.cpp
// Initializing an array's elements to zeros and printing the array.
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main()
{
	array< int, 10 > n; // n is an array of 10 int values
	double average{ 0.0 };
	
	srand(static_cast<unsigned int>(time(0))); // seed random generator using the current time

	// initialize the elements of array n to 0
	for (size_t i = 0; i < n.size(); ++i) {
		n[i] = (1 + rand() % 100); // set element at location i to random value between 1 and 100.
		average += n[i];
	}
	
	average /= n.size(); // calculate average

	cout << "Element" << setw(13) << "Value" << endl;

	// output each array element's value
	for (size_t j = 0; j < n.size(); ++j)
		cout << setw(7) << j << setw(13) << n[j] << endl;
	
	cout << fixed << setprecision(2); // beautify output
	cout << "\nAverage of array values is: " << average << "\n"; // print average

} // end main
