#ifndef __STUDENT_H__
#define __STUDENT_H__
#include "CommunityMember.h"


class Student
	: public CommunityMember
{
public:
	Student(string cName, string fName, string lName, int mID);
	virtual string GetCommunityMemberType();
};


#endif