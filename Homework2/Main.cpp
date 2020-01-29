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
#include <iomanip>
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

	//Will loop until the user exits by entering -1 for any input value. 
	//It will validate all inputs and then returns the balance, if below the credit limit. Or, the statement and the balance, if above the credit limit. 
	std::cout << "Enter the customer financial data below (-1 to stop): \n";
	do
	{
		//Input the account number and validate.
		accountNumber = Utilities::getIntInputValidate("Enter account number (or -1 to quit): ", "Account Number");
		if (accountNumber == -1)
		{
			break;
		}
		else
		{
			customer.setAccountNumber(accountNumber);
		}

		//Input the beginning balance and validate.
		beginningBalance = Utilities::getDoubleInputValidate("Enter beginning balance: ", "Beginning Balance");
		if (beginningBalance == -1)
		{
			break;
		}
		else
		{
			customer.setBeginningBalance(beginningBalance);
		}
		
		//Input the total monthly charges and validate.
		totalMonthlyCharges = Utilities::getDoubleInputValidate("Enter total charges: ", "Total Monthly Charges");
		if (totalMonthlyCharges == -1)
		{
			break;
		}
		else
		{
			customer.setTotalMonthlyCharges(totalMonthlyCharges);
		}
		
		//Input the total monthly credits and validate.
		totalMonthlyCreditsApplied = Utilities::getDoubleInputValidate("Enter total credits: ", "Monthly Credits Applied");
		if (totalMonthlyCreditsApplied == -1)
		{
			break;
		}
		else
		{
			customer.setTotalMonthlyCreditsApplied(totalMonthlyCreditsApplied);
		}

		//Input the allowed credit limit and validate.
		allowedCreditLimit = Utilities::getDoubleInputValidate("Enter credit limit: ", "Allowed Credit Limit");
		if (allowedCreditLimit == -1)
		{
			break;
		}
		else
		{
			customer.setAllowedCreditLimit(allowedCreditLimit);
		}

		//Beautify the output to print with 2 decimal points using fixed notation
		std::cout << std::fixed << std::setprecision(2); 

		//Calculate the customer new balance, based on the input values and print:
		//balance or balance and statement, if the balance is above the credit limit.
		customer.calculateNewBalance();
		std::cout << "New balance is " << customer.getBalance() << "\n";
		if (customer.getAllowedCreditLimit() < customer.getBalance())
		{
			std::cout << "Account:       " << customer.getAccountNumber() << "\n";
			std::cout << "Credit limit:  " << customer.getAllowedCreditLimit() << "\n";
			std::cout << "Balance:       " << customer.getBalance() << "\n";
			std::cout << "Credit Limit Exceeded. \n";
		}
		std::cout << "\n"; //New line to separate the outputs
	} while (true);

};
