#include "CommunityMember.h"
#include "Student.h"

// initialization constructor
// initialize our base class with pertinent information
// then initialize this derived class data with the remaining pertinent data
Student::Student(string cName, string fName, string lName, int memID)
	: CommunityMember(cName, fName, lName, memID)
{
	// no body needed. everthing was done in the initialization list
}


string Student::GetCommunityMemberType()
{
	return "My name is " + GetFirstName() + ". I am a student of the " + GetCommunityName() + " community!\n";
}
