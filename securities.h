#ifndef SECURITIES_H
#define	SECURITIES_H
#include <iostream>
#include <string>
using namespace std; 



#define API  "cvh1j41r01qi76d5vvcgcvh1j41r01qi76d5vvd0";          //API key for finnhub data



class Security { 

	protected:
		string symbol; 
		string name; 
		mutable double currentPrice; 
			

	public: 
	
		explicit Security(string sym, string nm);		//constructor
		virtual ~Security(); 					//deconstructor
		virtual void displayInfo() const = 0; 			//displays a securities info

		string getSymbol() const; 
		string getName() const;   
		double getValue(double qty) const; 
		double getPrice() const; 		

		void updatePrice() const; 				//updates price 
		
}; 












#endif
