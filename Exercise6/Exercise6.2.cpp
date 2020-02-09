// Fig. 7.3: fig07_03.cpp
// Initializing an array's elements to zeros and printing the array.
#include <iostream>
#include <iomanip>
#include <array>
#include <random>

const size_t rows{ 10 }; //Number of rows in array
const size_t columns{ 10 }; //Number of columns in array
void printArray(const std::array < std::array <int, columns>, rows>& anArray, double &);

//Intialize the two-dimensional array with random values.
void initializeRandomArray(std::array < std::array <int, columns>, rows>& anArray)
{
	std::default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	std::uniform_int_distribution<unsigned int> randomInt{ 1, 100 };

	//Loop to set array element to random values
	for (std::array <int, columns> & row : anArray)
	{
		for (int& element : row)
		{
			element = randomInt(engine);
		}
	}
}

//Print the two dimensional array and calculates the average of the values.
void printArray(const std::array < std::array <int, columns>, rows>& anArray, double &average)
{
	for (auto const& row : anArray)
	{
		for (auto const& element : row)
		{
			std::cout << std::setw(3) << element << " ";
			average += element;

		}
		std::cout << "\n";
	}

	average /= columns * rows;
}

int main()
{
	std::array <std::array< int, columns >, rows> randomizedArray = { 0 }; // n is an array of 10 int values
	double average{ 0.0 };


	// initialize the elements of two-dimensional array n to random values between 1 and 100
	initializeRandomArray(randomizedArray);

	// print out the two-dimensional array
	printArray(randomizedArray, average);

	std::cout << "\nThe average of the values of the array elements = " << std::fixed << std::setprecision(0) << std::round(average) << "\n";

	
} // end main
