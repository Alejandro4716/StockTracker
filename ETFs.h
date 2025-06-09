#ifndef STOCKS_H
#define STOCKS_H
#include "securities.h"
using namespace std;

class ETF : public Security { 

	//includes everything in Security class

	private: 
		
		const double expenseRatio;	


	public: 

		ETF(string sym, string nm); 			//constructor 
		void displayInfo() const override; 		//overrides displayInfo in Security class
		void setExpenseRatio(); 
		double getExpenseRatio(); 
}; 

#endif 
