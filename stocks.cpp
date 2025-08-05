#include "stocks.h"

//constructor
Stock::Stock (string sym, string nm) : Security(sym, nm){} 


//displays a stocks information 
void Stock::displayInfo() const { 

	cout << getSymbol() << ": " << " @ " << getPrice() <<endl; 
}; 


























