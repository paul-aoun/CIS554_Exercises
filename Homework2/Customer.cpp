//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #2 -  Exercise 4.14 p150						//
//													//
// 1/27/2020										//
//												    //
// This is the Customer class.						//
// A customer object stores the financials of the 	//
// customer and calculates their credit lmit.		//
//////////////////////////////////////////////////////
#include <string>
#include "Customer.h"

//Getter function for Account Number. 
int Customer::getAccountNumber()
{
	return accountNumber;
}

//Setter function for Account Number. If the account number passed is negative, it will leave it unchanged.
void Customer::setAccountNumber(int an)
{
	if (an > 0)
	{
		accountNumber = an;
	}
	else
	{
		std::cout << "Invalid account number! \n";
	}
}

//Getter function for Allowed Credit Limit. 
double Customer::getAllowedCreditLimit()
{
	return allowedCreditLimit;
}

//Setter function for Allowed Credit Limit. If the allowed credit limit passed is negative, it will leave it unchanged.
void Customer::setAllowedCreditLimit(double acl)
{
	if (acl > 0)
	{
		allowedCreditLimit = acl;
	}
	else
	{
		std::cout << "Invalid Allowed Credit Limit! \n";
	}
}

//Getter function for Customer balance.
double Customer::getBalance()
{
	return balance;
}

//Getter function for Beginning Balance. 
double Customer::getBeginningBalance()
{
	return beginningBalance;
}

//Setter function for Beginning Balance. Beginning Balance can be positive or negative.
void Customer::setBeginningBalance(float bb)
{
	beginningBalance = bb;
}

//Getter function for Total Monthly Charges. 
double Customer::getTotalMonthlyCharges()
{
	return totalMonthlyCharges;
}

//Setter function for Total Monthly Charges. If the total monthly charges passed is negative, it will leave it unchanged.
void Customer::setTotalMonthlyCharges(double tmc)
{
	if (tmc > 0)
	{
		totalMonthlyCharges = tmc;
	}
	else
	{
		std::cout << "Invalid total monthly charges! \n";
	}
}

//Getter function for Total Monthly Credits Applied. 
double Customer::getTotalMonthlyCreditsApplied()
{
	return totalMonthlyCreditsApplied;
}

//Setter function for Total Credits Applied. If the total monthly credits applied passed is negative, it will leave it unchanged.
void Customer::setTotalMonthlyCreditsApplied(double tmca)
{
	if (tmca > 0)
	{
		totalMonthlyCreditsApplied = tmca;
	}
	else
	{
		std::cout << "Invalid total monthly credits applied! \n";
	}
}

//Calculates the customer's new balance.
void Customer::calculateNewBalance()
{

	balance = beginningBalance + totalMonthlyCharges - totalMonthlyCreditsApplied;

}

////Prepares and returns the customer financial statement
std::string Customer::getCustomerFinancialStatement()
{
	std::string statement{ "" };
	statement = "Account:      " + std::to_string(accountNumber) + "\n";
	std::size_t dotPosition = statement.find(".");      // position of "." in string
	std::string str3 = statement.substr(dotPosition + 2);
	statement += "Credit limit: " + std::to_string(allowedCreditLimit) + "\n";
	statement += "Balance:      " + std::to_string(balance) + "\n";

	return statement;

}