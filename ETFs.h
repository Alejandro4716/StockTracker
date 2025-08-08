#ifndef ETFs_H
#define ETFs_H
#include "securities.h"
using namespace std;

class ETF : public Security { 

	//includes everything in Security class

	private: 
		
		//expense ratio of the ETF
		mutable double expenseRatio;	
		mutable double NAVPS; //net asset value per share of the ETF
		mutable double AUM; //assets under management


	public: 

		ETF(string sym, string nm); 			//constructor 

		void displayInfo() const override; 		//overrides displayInfo in Security class
		void updateData() const override; 		//updates ETF data (expense ratio and net assets)

		double getExpenseRatio() const; 		//returns the expense ratio of the ETF
		double getNAVPS() const; 			//returns the net asset value per share of the ETF
		double getAUM() const; 			//returns the assets under management of the ETF
}; 

#endif 
