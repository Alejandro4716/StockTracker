#ifndef STOCKS_H
#define STOCKS_H
#include "securities.h"
using namespace std; 


class Stock : public Security { 

	//includes everything in Security class

	public: 
		explicit Stock(string sym, string nm); 		//constructor
		void displayInfo() const override;		//overrides displayInfo in Security class
}; 


 
		
#endif

