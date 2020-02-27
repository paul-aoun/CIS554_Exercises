//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #6 - Exercise 9.20        					//
//													//
// 2/26/2020										//
//												    //
// This is the driver file for the Savings Account	//
// class.                                       	//
// It tests setting calculate the earned monthly	//
// interest based on a given interest rate and      //
// changing the interest rate then recalculating    //
// the earned interest and balances for 2 saviers.  //
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "Main.h"

void printMonthlyInterestBalances(SavingsAccount& saver1, SavingsAccount& saver2)
{
    //Calculate monthly interest for the 2 saviers
    double monthlyInterest1 = saver1.calculateMonthlyInterest();
    double monthlyInterest2 = saver2.calculateMonthlyInterest();

    //Print the monthly interest earned for the two saviers.
    std::cout << "Saver1: " << saver1.getFirstName() << " " << saver1.getLastName() << " monthly interest is: $" <<
        monthlyInterest1 << "\n";
    std::cout << "Saver2: " << saver2.getFirstName() << " " << saver2.getLastName() << " monthly interest is: $" <<
        monthlyInterest2 << "\n";
    //Print the monthly balances for the two saviers.
    std::cout << "\nCustomers Balance Statements: \n";
    std::cout << saver1.printBalances() << "\n";
    std::cout << saver2.printBalances();
}

int main()
{
    //Sets the initial values for the balances and the interest rate.
    const double balance1 = 2000.0;
    const double balance2 = 3000.0;
    double interestRate = 0.03;
    double monthlyInterest1{ 0.0 }, monthlyInterest2{ 0.0 };

    
    //Create the 2 savers accounts, set their names and their initial balances.
    SavingsAccount saver1, saver2;
    saver1.setFirstName("John");
    saver1.setLastName("Doe");
    saver2.setFirstName("Jane");
    saver2.setLastName("Doe");
    saver1.setSavingsBalance(balance1);
    saver2.setSavingsBalance(balance2);

    std::cout << "Welcome to CIS 554-M401 Bank! We appreaciate your business.\n";
    
    std::cout << "Interest rate is: " << interestRate*100 << "%\n";
    //Set the interest rate at 3% and print statement.
    SavingsAccount::modifyInterestRate(interestRate);
    printMonthlyInterestBalances(saver1, saver2);

    //Set the interest rate at 4% and print statement.
    interestRate = 0.04;
    std::cout << "\nInterest rate is: " << interestRate*100 << "%\n";
    SavingsAccount::modifyInterestRate(interestRate);
    printMonthlyInterestBalances(saver1, saver2);

}
