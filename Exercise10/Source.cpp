///////////////////////////////////////////////////////////
// Source.cpp
// CIS554 Object Oriented Programming in C++
// Exercise 10_1 - Polymorphism
//                program test 
///////////////////////////////////////////////////////////

#include "CommunityMember.h"
#include "Employee.h"
#include "Student.h"
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

void PrintMemberType(CommunityMember*);

int main()
{
	// create a vector of default CommunityMember objects
	vector<CommunityMember*> communityMemberVector(2);

	// initialize some CommunityMember objects
	Employee carrieUnderwood("Syracuse University", "Carrie", "Underwood", 5678, "Country Singer", 1000000);
	Student willieSwift("Syracuse University", "Willie", "Swift", 1234);

	// re-assign default objects in our vector to our newly created members
	communityMemberVector[0] = &carrieUnderwood;  // Employee type
	communityMemberVector[1] = &willieSwift;      // Student type

	// print out each member's type
	for (auto item : communityMemberVector)
	{
		PrintMemberType(item);
	}

	return 0;
}

// method to print out CommunityMember types given a CommunityMember object
void PrintMemberType(CommunityMember* member)
{
	cout << (*member).GetCommunityMemberType();
}

