#ifndef ETFs_H
#define ETFs_H
#include "securities.h"
using namespace std;

class ETF : public Security { 

	//includes everything in Security class

	private: 
		
		double expenseRatio;	


	public: 

		ETF(string sym, string nm); 			//constructor 
		void displayInfo() const override; 		//overrides displayInfo in Security class
		void setExpenseRatio(); 
		double getExpenseRatio() const; 
}; 

#endif 
