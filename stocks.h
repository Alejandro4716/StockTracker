#ifndef STOCKS_H
#define STOCKS_H
#include "securities.h"
using namespace std; 


class Stock : public Security { 

	//includes everything in Security class
	private: 
		mutable double high; 
		mutable double low;
		mutable double open;
		mutable double prevClose;


	public: 
		explicit Stock(string sym, string nm); 		//constructor
		void displayInfo() const override;		//overrides displayInfo in Security class
		void updateData() const override; 		//updates open, previous close, high, and low prices

		double getHigh() const; 			//returns the high price of the stock
		double getLow() const; 			//returns the low price of the stock
		double getOpen() const; 			//returns the open price of the stock
		double getPrevClose() const; 		//returns the previous close price of the stock
}; 


 
		
#endif

