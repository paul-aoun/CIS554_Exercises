//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
//													//
// 2/26/2020										//
//													//
// This is the header file for the SavingsAccount 	//
// class. It declares the functions needed to		//
// manage the savers savings accounts.				//
//////////////////////////////////////////////////////
#include <string>

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
private:
	
	//Hold the annual interest for all the savers
	static double annualInterestRate;
	
	//Savings balance for the savers
	double savingsBalance{ 0.0 };

	//Name of the savers
	std::string firstName{ "" }, lastName{ "" };
	

public:

	//Modify the interest rate for all savers.
	static void modifyInterestRate(double);

	//Calculate the monthly interest earned based on the interest rate
	double calculateMonthlyInterest();

	//Setter and getter functions for the savings balance
	const double getSavingsBalance() const;
	void setSavingsBalance(double);

	//Setter and getter functions for the name
	const std::string getFirstName() const;
	const std::string getLastName() const;
	void setFirstName(std::string);
	void setLastName(std::string);

	//Prepare the statement balance for the savier.
	std::string printBalances();

};

#endif SAVINGSACCOUNT_H
