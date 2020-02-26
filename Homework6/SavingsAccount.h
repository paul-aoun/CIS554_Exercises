#include <string>

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
private:
	static double annualInterestRate;
	double savingsBalance{ 0.0 };
	std::string firstName{ "" }, lastName{ "" };
	

public:
	static void modifyInterestRate(double);
	double calculateMonthlyInterest();
	const double getSavingsBalance();
	void setSavingsBalance(double);
	const std::string getFirstName();
	const std::string getLastName();
	void setFirstName(std::string);
	void setLastName(std::string);
	std::string printBalances();

};

#endif SAVINGSACCOUNT_H
