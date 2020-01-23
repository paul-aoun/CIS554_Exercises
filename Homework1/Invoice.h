//////////////////////////////////////////////////////
// Paul Aoun										//
// CIS 554-M401 Object Oriented Programming in C++  //
//													//
// Syracuse University								//				
// HW #1 -  Exercise 3.10 p100						//
//													//
// 1/21/2020										//
//												    //
// This is the header file for the Invoice class.	//
// An invoice object store the parameters of the	//
// invoice and calculates its amount.				//
//////////////////////////////////////////////////////
#include <string>

class Invoice {

private:
	//Storing the default values in constants to avoid hardcoding in the definition of the constructor.
	const double defaultRate{ 0.0 };
	const double defaultVAT{ 0.002 };
	
	//Variables to store the details of the invoices
	std::string partNumber{ "" };
	std::string partDescription{ "" };
	int quantity{ 0 };
	int price{ 0 };
	double vat{ 0.0 };
	double discountRate{ 0.0 };	

public:
	//Constructor with parameters. Will set default values to VAT equals to 0.2% and discount rate equals to 0%.
	explicit Invoice(std::string aPartNum, std::string aPartDesc, int aQuantity, int aPrice);
	
	//Getter and setter functions for Part Number. The setter function checks if the passed string is empty and, if so, sets the part number to empty string.
	std::string getPartNumber();
	void setPartNumber(std::string);

	//Getter and setter functions for Part Description. The setter function checks if the passed string is empty and, if so, sets the part description to empty string.
	std::string getPartDescription();
	void setPartDescription(std::string);

	//Getter and setter functions for part quantity. The setter function checks if the passed quantity is negative and, if so, sets the part quantity to zero.
	int getQuantity();
	void setQuantity(int);

	//Getter and setter functions for part price. The setter function checks if the passed price is negative and, if so, sets the price to zero.
	int getPrice();
	void setPrice(int);

	//Getter and setter functions for invoice VAT. The setter function checks if the passed VAT is negative or greater than 100 and, if so, leaves it unchanged.
	double getVAT();
	void setVAT(double);

	//Getter and setter functions for invoice discount. The setter function checks if the passed discount is negative or greater than 100 and, if so, leaves it unchanged.
	double getDiscountRate();
	void setDiscountRate(double);

	//Calculates the invoice amount using the following formula: invoice amount = (quantity  * price) * (1 + VAT%) * (1 - discount rate)
	double getInvoiceAmount();

};

