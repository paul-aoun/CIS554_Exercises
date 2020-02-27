//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/26/2020										//
//													//
// This is the file for the SavingsAccount class.	//
// It defines the functions needed to				//
// manage the savers savings accounts.				//
//////////////////////////////////////////////////////
#include <sstream>
#include <iomanip>
#include "SavingsAccount.h"

double SavingsAccount::annualInterestRate{ 0.0 };

//Prepare the statement balance for the savier.
//Return a well-formatted string.
std::string SavingsAccount::printBalances()
{
	std::ostringstream balanceStr;
	balanceStr << std::setw(18) << "First Name: " << getFirstName() << "\n";
	balanceStr << std::setw(18) << "Last Name: " <<  getLastName() << "\n";
	balanceStr << std::setw(18) << "Balance is: " << getSavingsBalance() << "\n";
	return balanceStr.str();
}

//Modify the interest rate for all savers.
void SavingsAccount::modifyInterestRate(double interestRate)
{
	SavingsAccount::annualInterestRate = interestRate;
}

//Calculate the monthly interest earned based on the interest rate.
double SavingsAccount::calculateMonthlyInterest() {
	double monthlyInterest = SavingsAccount::annualInterestRate * savingsBalance / 12.0;
	savingsBalance += monthlyInterest;
	return monthlyInterest;
}

//Getter function for the savings balance. savings balance.
const double SavingsAccount::getSavingsBalance() const
{
	return savingsBalance;
}
//Setter function for the savings balance.
void SavingsAccount::setSavingsBalance(double balance)
{
	savingsBalance = balance;
}

//Getter function for the savier's first name
const std::string SavingsAccount::getFirstName() const
{
	return firstName;
}

//Getter function for the savier's last name
const std::string SavingsAccount::getLastName() const
{
	return lastName;
}

//Setter function for the savier's first name
void SavingsAccount::setFirstName(std::string aFirstName)
{
	firstName = aFirstName;
}

//Setter function for the savier's last name
void SavingsAccount::setLastName(std::string aLastName)
{
	lastName = aLastName;
}
