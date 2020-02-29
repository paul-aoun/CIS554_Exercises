// CIS554 Object Oriented Programming in C++
// Exercise 9_1 - Simple Intheritance
//                Class Student interface
///////////////////////////////////////////////////////////
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "CommunityMember.h"
class Student :
	public CommunityMember
{
public:

	// default constructor
	Student();

	// initialization contstructor
	Student(string cName, string fName, string lName, int memID, string studentDepartment, double studentGPA);

	// destructor
	~Student();

	string GetStudentDeparment();
	double GetStudentGPA();

	//Override CommunityMember method
	int GetMemberID();

private:
	string studentDepartment{ "" };
	double studentGPA{ 0 };
};
#endif