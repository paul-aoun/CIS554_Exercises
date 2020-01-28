//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #2 -  Exercise 4.14 p150						//
//													//
// 1/27/2020										//
//												    //
// This is the driver file for the Customer class.	//
// A customer object store the financial parameters //
// of the customer and calculates their balance. 	//
// This files will prompt the users for the updated //
// financical paramters and calcutes the balance.	//
//////////////////////////////////////////////////////
#include <iostream>
#include "Utilities.h"
#include "Customer.h"

int main()
{
	bool continueLooping{ true };

	int accountNumber{ 0 };
	double beginningBalance{ 0.0 };
	double totalMonthlyCharges{ 0.0 };
	double totalMonthlyCreditsApplied{ 0.0 };
	double allowedCreditLimit{ 0.0 };
	double balance{ 0.0 };

	Customer customer;

	//Will loop until the user exits by entering -1 for any time value. 
	//It will validate all inputs and then returns the seconds elapsed since noon. 
	std::cout << "Enter the customer financial data below (-1 to stop): \n";
	do
	{

		accountNumber = Utilities::getIntInputValidate("Enter account number (or -1 to quit): ");
		if (accountNumber == -1)
		{
			break;
		}

		beginningBalance = Utilities::getDoubleInputValidate("Enter beginning balance: ");
		totalMonthlyCharges = Utilities::getDoubleInputValidate("Enter total charges: ");
		totalMonthlyCreditsApplied = Utilities::getDoubleInputValidate("Enter total credits: ");
		allowedCreditLimit = Utilities::getDoubleInputValidate("Enter credit limit: ");

		customer.calculateNewBalance();
		if (customer.getAllowedCreditLimit() < customer.getBalance())
		{
			std::cout << customer.getCustomerFinancialStatement() + "Credit Limit Exceeded. \n";
		}
		else if (customer.getAllowedCreditLimit() >= customer.getBalance())
		{
			std::cout << "New balance is " << customer.getBalance() << "\n";
		}


	} while (true);

};
