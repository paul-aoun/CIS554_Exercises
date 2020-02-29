#include "Student.h"

Student::Student() 
	: studentDepartment("Non-matriculated"), studentGPA(0.0)
{
}

Student::Student(string cName, string fName, string lName, int memID, string studentDepartment, double studentGPA)
	: CommunityMember(cName, fName, lName, memID), studentDepartment(studentDepartment), studentGPA(studentGPA)
{
}

Student::~Student()
{
}
