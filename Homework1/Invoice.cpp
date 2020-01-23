//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #1 -  Exercise 3.10 p100						//
//													//
// 1/21/2020										//
//												    //
// This is for the Invoice class. It includes		//
// the definition of all the getter/setter functions//
// and has the constructor and function to calculate//
// the invoice amount.								//
// An invoice object store the parameters of the	//
// invoice and calculates its amount.				//
//////////////////////////////////////////////////////
#include <iostream>
#include "Invoice.h"

//Constructor with parameters. Will set default values for VAT equals to 0.2% and discount rate equals to 0%.
Invoice::Invoice(std::string aPartNum, std::string aPartDesc, int aQuantity, int aPrice):
	partNumber{aPartNum}, partDescription{aPartDesc}, quantity{aQuantity}, price{aPrice}, vat{Invoice::defaultVAT}, discountRate{Invoice::defaultRate}
{
}

//Returns the part number.
std::string Invoice::getPartNumber()
{
	return partNumber;
}
//Sets the part number. If the passed part number is empty, it will set the part number to "NA".
void Invoice::setPartNumber(std::string aPartNumber)
{
	if (!(aPartNumber.empty()))
		partNumber = aPartNumber;
	else
		partNumber = "NA";
}

//Returns the part description.
std::string Invoice::getPartDescription()
{
	return partDescription;
}
//Sets the part description. If the passed part description is empty, it will set the part description to "NA".
void Invoice::setPartDescription(std::string aPartDescription)
{
	if (!(aPartDescription.empty()))
		partDescription = aPartDescription;
	else
		partDescription = "NA";
}

//Returns the quantity.
int Invoice::getQuantity()
{
	return quantity;
}
//Sets the quantity. If the passed quantity is negative, it will leave the quantity unchanged.
void Invoice::setQuantity(int aQuantity)
{
	if (aQuantity >= 0) {
		quantity = aQuantity;
	}		
	else {
		std::cout << "Invalid quantity. Quantity left unchanged." << std::endl;
	}
		
}

//Returns the price
int Invoice::getPrice()
{
	return price;
}
//Sets the price. If the passed price is negative, it will leave the price unchanged.
void Invoice::setPrice(int aPrice)
{
	if (aPrice >= 0) {
		price = aPrice;
	}
	else {
		std::cout << "Invalid price. Price left unchanged." << std::endl;
	}
}

//Returns the VAT
double Invoice::getVAT()
{
	return vat;
}
//Sets the VAT. If the passed VAT is negative or greater 100, it will leave the VAT unchanged
void Invoice::setVAT(double aVAT)
{
	if ((aVAT >= 0) && (aVAT <= 100)) {
		vat = aVAT;
	}
	else {
		std::cout << "Invalid VAT. VAT left unchanged." << std::endl;
	}
}

//Returns the discount rate.
double Invoice::getDiscountRate()
{
	return discountRate;
}
//Sets the discount rate. If the passed discount rate is negative or greater than 100, it will leave the discount rate unchanged.
void Invoice::setDiscountRate(double aDiscountRate)
{
	if ((aDiscountRate >= 0) && (aDiscountRate <= 100)) {
		discountRate = aDiscountRate;
	}
	else {
		std::cout << "Invalid discount rate. Discount rate left unchanged." << std::endl;
	}
}

//Calculates the invoice amount using the following formula: invoice amount = (quantity  * price) * (1 - discount rate) * (1 + VAT%)
double Invoice::getInvoiceAmount()
{
	return (static_cast <double> (quantity) * price) * (1 - discountRate/100.0) * (1 + vat/100.0);
}


