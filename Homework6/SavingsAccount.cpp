#include <sstream>
#include <iomanip>
#include "SavingsAccount.h"

double SavingsAccount::annualInterestRate{ 0.0 };

std::string SavingsAccount::printBalances()
{
	std::ostringstream balanceStr;
	balanceStr << std::setw(18) << "First Name: " << getFirstName() << "\n";
	balanceStr << std::setw(18) << "Last Name: " <<  getLastName() << "\n";
	balanceStr << std::setw(18) << "Balance is: " << getSavingsBalance() << "\n";
	return balanceStr.str();
}

void SavingsAccount::modifyInterestRate(double interestRate)
{
	SavingsAccount::annualInterestRate = interestRate;
}

double SavingsAccount::calculateMonthlyInterest() {
	double monthlyInterest = SavingsAccount::annualInterestRate * savingsBalance / 12.0;
	savingsBalance += monthlyInterest;
	return monthlyInterest;
}

const double SavingsAccount::getSavingsBalance()
{
	return savingsBalance;
}

void SavingsAccount::setSavingsBalance(double balance)
{
	savingsBalance = balance;
}

const std::string SavingsAccount::getFirstName()
{
	return firstName;
}

const std::string SavingsAccount::getLastName()
{
	return lastName;
}

void SavingsAccount::setFirstName(std::string aFirstName)
{
	firstName = aFirstName;
}

void SavingsAccount::setLastName(std::string aLastName)
{
	lastName = aLastName;
}
