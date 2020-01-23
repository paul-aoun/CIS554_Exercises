//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #1 -  Exercise 3.10 p100						//
//													//
// 1/21/2020										//
//												    //
// This is the driver file for the Invoice class.	//
// An invoice object store the parameters of the	//
// invoice and calculates its amount.				//
// This files will prompt the users for the invoice //
// paramters and calcute its amount.				//
//////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include "Invoice.h"

int main() {

	//Declare and initialize the variables needed.
	std::string partNumber{ "" };
	std::string partDescription{ "" };
	int quantity{ 0 };
	int price{ 0 };
	double vat{ 0.002 };
	double discountRate{ 0.0 };
	char moreInvoices{ 'Y' };
	bool continueToPrepareInvoices = true;

	//Create invoice object
	Invoice invoice(partNumber, partDescription, quantity, price);

	//While loop to prepare invoices until the users is done.
	while (continueToPrepareInvoices == true) {

		//Input the invoice parameters from the user
		std::cout << "Enter Part Number (no spaces or special characters): " << std::endl;
		std::cin >> partNumber;

		std::cout << "Enter Part Description (no spaces or special characters): " << std::endl;
		std::cin >> partDescription;

		std::cout << "Enter Quantity (integer value): " << std::endl;
		std::cin >> quantity;

		std::cout << "Enter Price (integer value): " << std::endl;
		std::cin >> price;
		
		std::cout << "Enter VAT (between 0% and 100%): " << std::endl;
		std::cin >> vat;
		
		std::cout << "Enter Discount Rate (between 0% and 100%): " << std::endl;
		std::cin >> discountRate;
		
		//Set the invoice parameters based on input using the setter functions.
		invoice.setPartNumber (partNumber);
		invoice.setPartDescription (partDescription);
		invoice.setQuantity(quantity);
		invoice.setPrice (price);
		invoice.setVAT(vat);
		invoice.setDiscountRate(discountRate);
		
		//Beautify the output by using fixed notation and setting the precision to 2.
		std::cout << std::setprecision(2) << std::fixed;

		//Prints out the invoice parameters including the amount.
		std::cout << "Part Number is " << invoice.getPartNumber() << std::endl;
		std::cout << "Part Description is " << invoice.getPartDescription() << std::endl;
		std::cout << "Quantity is " << invoice.getQuantity() << std::endl;
		std::cout << "Price is " << invoice.getPrice() << std::endl;
		std::cout << "VAT is " << invoice.getVAT() << std::endl;
		std::cout << "Discount Rate is " << invoice.getDiscountRate() << std::endl;
		std::cout << "Invoice Amount is " << invoice.getInvoiceAmount() << std::endl;
		
		//Block of codes to ask the user if there are more invoices to prepare. If 'Y", continue looping, and, if not, exit the loop and stop.
		std::cout << "More Invoices to Prepare Y/N? " << std::endl;
		std::cin >> moreInvoices;
		((moreInvoices == 'Y' ) || (moreInvoices == 'y'))? continueToPrepareInvoices = true : continueToPrepareInvoices = false;
	}

};