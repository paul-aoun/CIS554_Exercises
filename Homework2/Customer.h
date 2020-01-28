//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #2 -  Exercise 4.14 p150						//
//													//
// 1/27/2020										//
//													//
// This is the header file for the Customer class.	//
// A customer object stores the financials of the 	//
// customer and calculates their credit lmit.		//
//////////////////////////////////////////////////////
#include <iostream>

class Customer
{

private: 
	int accountNumber{ 0 };
	double beginningBalance{ 0.0 };
	double totalMonthlyCharges{ 0.0 };
	double totalMonthlyCreditsApplied{ 0.0 };
	double allowedCreditLimit{ 0.0 };
	double balance{ 0.0 };

public:

	//Getter function for Account Number. 
	int getAccountNumber();
	//Setter function for Account Number. If the account number passed is negative, it will leave it unchanged.
	void setAccountNumber(int);

	//Getter function for Beginning Balance. 
	double getBeginningBalance();
	//Setter function for Beginning Balance. Beginning Balance can be positive or negative.
	void setBeginningBalance(float bb);
	
	//Getter function for Total Monthly Charges. 
	double getTotalMonthlyCharges();
	//Setter function for Total Monthly Charges. If the total monthly charges passed is negative, it will leave it unchanged.
	void setTotalMonthlyCharges(double tmc);
	
	//Getter function for Total Monthly Credits Applied. 
	double getTotalMonthlyCreditsApplied();
	//Setter function for Total Credits Applied. If the total monthly credits applied passed is negative, it will leave it unchanged.
	void setTotalMonthlyCreditsApplied(double tmca);

	//Getter function for Allowed Credit Limit. 
	double getAllowedCreditLimit();
	//Setter function for Allowed Credit Limit. If the allowed credit limit passed is negative, it will leave it unchanged.
	void setAllowedCreditLimit(double);

	//Calculates the customer's new balance.
	void calculateNewBalance();
	//Getter function for Customer balance.
	double getBalance();

	std::string getCustomerFinancialStatement();

};