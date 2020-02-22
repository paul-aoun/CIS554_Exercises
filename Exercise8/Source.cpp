///////////////////////////////////////////////////////////
// Source.cpp 
// CIS554 Object Oriented Programming in C++
// Exercise 8_1 - Operator Overloading - member functions
//                program file
///////////////////////////////////////////////////////////

#include "loc.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	loc ob1(10, 20), ob2(5, 30), ob3;

	// demonstrate constructor
	cout << "Show proper construction of ob1 and ob2" << endl;
	cout << "Object ob1 = ";
	ob1.show(); // displays 10 20
	cout << "Object ob2 = ";
	ob2.show(); // displays 5 30
	cout << endl;

	//demonstrate operator+ 
	cout << "Show operator+" << endl;
	cout << "(ob1 + ob2).show= ";
	(ob1 + ob2).show();
	cout << endl;

	// default operator=
	cout << "Show default assignment operator" << endl;
	cout << "ob3 = ob1 + ob2 = ";
	ob3 = ob1 + ob2;
	ob3.show();
	cout << endl;

	// demonstrate that original loc objects have not been modified
	cout << "Show that original objects have not been modified" << endl;
	cout << "Object ob1= ";
	ob1.show();
	cout << "Object ob2= ";
	ob2.show();
	cout << endl;

	//demonstrate operator+ 
	cout << "Show operator+=" << endl;
	cout << "(ob1 += ob2).show= ";
	(ob1 += ob2).show();
	cout << endl;

	// default operator=
	cout << "Show default assignment operator" << endl;
	cout << "ob3 = ob1 += ob2 = ";
	ob3 = ob1 += ob2;
	ob3.show();
	cout << endl;

	// demonstrate that original loc objects have not been modified
	cout << "Show that original objects have not been modified" << endl;
	cout << "Object ob1= ";
	ob1.show();
	cout << "Object ob2= ";
	ob2.show();
	cout << endl;

	return 0;
}
