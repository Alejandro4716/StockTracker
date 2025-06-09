#ifndef MUTUAL_FUNDS
#define MUTUAL_FUNDS
#include "securities.h"
using namespace std; 

class MutualFund : public Security   { 

	//includes everything in Security class
	

	private: 

		const double minPurchaseAmt; 

	public: 
		MutualFund(string sym, string nm); 		//constructor
		void displayInfo() const override; 		//overrides displayInfo
		double getMinPurchaseAmt() const; 
}; 

#endif










