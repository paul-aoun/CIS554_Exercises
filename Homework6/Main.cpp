// Homework6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include<cmath>
#include "SavingsAccount.h"

int main()
{
    const double balance1 = 2000.0;
    const double balance2 = 3000.0;
    const double interestRate = 0.03;
    double monthlyInterest1{ 0.0 }, monthlyInterest2{ 0.0 };

    SavingsAccount::modifyInterestRate(interestRate);
    SavingsAccount saver1, saver2;
    saver1.setSavingsBalance(balance1);
    saver2.setSavingsBalance(balance2);

    monthlyInterest1 = saver1.calculateMonthlyInterest();
    monthlyInterest2 = saver2.calculateMonthlyInterest();

    saver1.setFirstName("John");
    saver1.setLastName("Doe");

    std::time_t const now_c = std::time();
    std::cout << "One day ago, the time was "
        << std::put_time(std::localtime(&now_c), "%F %T") << '\n';
    auto end = std::chrono::system_clock::now();
    

    /*
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;
    

    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    std::cout << "\n\n Display the Current Date and Time :\n";
    std::cout << "----------------------------------------\n";
    std::cout << " seconds = " << (tPtr->tm_sec) << std::endl;
    */
    std::cout << "Welcome to CIS 554-M401 Bank! We appreaciate your business.\n";
    //std::cout << "As of " << std::ctime(&end_time) <<"\n";
    std::cout << saver1.getFirstName() << " " << saver1.getLastName() << " monthly interest is: $" <<
        monthlyInterest1 << "\n";
    saver2.setFirstName("Jane");
    saver2.setLastName("Doe");
    std::cout << saver2.getFirstName() << " " << saver2.getLastName() << " monthly interest is: $" <<
        monthlyInterest2 << "\n";

    std::cout << "\nCustomers Balance Statements: \n";
    std::cout << saver1.printBalances() <<"\n"; 
    std::cout << saver2.printBalances();

}
