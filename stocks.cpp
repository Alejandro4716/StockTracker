#include "stocks.h"

//constructor
Stock::Stock (string sym, string nm) : Security(sym, nm){} 


//displays a stocks information 
void Stock::displayInfo() const { 

	if (previousPrice == 0.0) {
		cout << setw(8) << getSymbol() << ": " << " @ " << getPrice() << endl; 
	}
	else if (currentPrice > previousPrice) {
		cout << "\033[32m" << setw(8) << getSymbol() << ": " << " @ " << getPrice() << endl; 
	}
	else if (currentPrice < previousPrice) {
		cout << "\033[31m" << setw(8) << getSymbol() << ": " << " @ " << getPrice() << endl; 
	}
	else {
		cout << setw(8) << getSymbol() << ": " << " @ " << getPrice() << endl; 
	}
}; 


























