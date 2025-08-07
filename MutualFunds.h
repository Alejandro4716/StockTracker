/*								logic works however finhub's free tier does not support mutual funds, so this is commented out
#ifndef MUTUAL_FUNDS
#define MUTUAL_FUNDS
#include "securities.h"
using namespace std; 

class MutualFund : public Security   { 

	//includes everything in Security class
	

	private: 

		//net asset value 
		double NAV; 

	public: 
		MutualFund(string sym, string nm); 		//constructor
		void displayInfo() const override; 		//overrides displayInfo
		double getNAV() const; 
		void setNAV();
}; 

#endif
*/ 










