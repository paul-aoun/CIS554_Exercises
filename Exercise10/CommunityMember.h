///////////////////////////////////////////////////////////
// CommunityMember.h
// CIS554 Object Oriented Programming in C++
// Exercise 10_1 - Polymorphism
//                Class CommunityMember interface
///////////////////////////////////////////////////////////
#ifndef __COMMUNITY_MEMBER_H__
#define __COMMUNITY_MEMBER_H__

#include <string>
using std::string;

#include <ostream>
using std::ostream;

class CommunityMember
{
public:

	// default constructor
	CommunityMember();

	// initialization constructor
	CommunityMember(string commName, string fName, string lName, int memID);

	// destructor
	~CommunityMember();

	string GetCommunityName() { return communityName; }
	string GetFirstName() { return firstName; }
	string GetLastName() { return lastName; }
	int GetMemberID() { return memberID; }
	virtual string GetCommunityMemberType();// { return "Base Class GetCommunityMemberType method called!!\n"; }



private:
	string communityName;
	string firstName;
	string lastName;
	int memberID;
};

#endif

