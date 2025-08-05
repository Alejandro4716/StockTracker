#ifndef ETFs_H
#define ETFs_H
#include "securities.h"
using namespace std;

class ETF : public Security { 

	//includes everything in Security class

	private: 
		
		//expense ratio of the ETF
		double expenseRatio;	


	public: 

		ETF(string sym, string nm); 			//constructor 
		void displayInfo() const override; 		//overrides displayInfo in Security class
		void setExpenseRatio(); 				//sets the expense ratio of the ETF by fetching data from the API	
		double getExpenseRatio() const; 		//returns the expense ratio of the ETF
}; 

#endif 
