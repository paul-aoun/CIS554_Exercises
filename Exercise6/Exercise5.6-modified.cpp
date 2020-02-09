// Fig. 7.3: fig07_03.cpp
// Initializing an array's elements to zeros and printing the array.
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

/*
int main()
{
	const size_t arraySize{ 10 };
	array< int, arraySize > n = { 0 }; // n is an array of 10 int values
	double average{ 0.0 };
	
	srand(static_cast<unsigned int>(time(0))); // seed random generator using the current time

	// initialize the elements of array n to 0
	for (int &nElement: n) {
		nElement = (1 + rand() % 100); // set element at location i to random value between 1 and 100.
		average += nElement;
	}
	
	average /= n.size(); // calculate average

	cout << "Element" << setw(13) << "Value" << endl;

	// output each array element's value
	int elementPosition{ 0 }; //used to print the element position
	for (int nElement : n)
		cout << setw(7) << ++elementPosition << setw(13) << nElement << endl;
	
	cout << fixed << setprecision(2); // beautify output
	cout << "\nAverage of array values is: " << average << "\n"; // print average

} // end main
*/