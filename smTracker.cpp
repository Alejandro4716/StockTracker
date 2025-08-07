#include <iostream>		//needed for input/output
#include <string> 		//needed for dealing with strings
#include <map>			//needed for map usage
#include <iomanip> 		//needed for formatting 
#include <cstdlib>		//needed for system calls 
#include <chrono>		//needed for time
#include <thread>		//needed for sleep
#include <vector>

#include "stocks.h"
#include "ETFs.h"
//#include "MutualFunds.h"		logic works however finhub's free tier does not support mutual funds, so this is commented out

using namespace std;			//simplicity 
using namespace std::this_thread; 	//sleep
using namespace std::chrono;		//time 





int main() { 
	
	//vector containg stock names 
	vector<unique_ptr<Security>> holdings;									//vector of security types

	holdings.emplace_back(make_unique<Stock>("AAPL", "Apple Inc."));		//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("GOOGL", "Alphabet Inc."));		//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("AMZN", "Amazon.com Inc."));		//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("MSFT", "Microsoft Corp."));		//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("NFLX", "Netflix Inc."));			//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("META", "Meta Platforms Inc."));	//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("NVDA", "NVIDIA Corp."));			//adds a stock to the holdings vector
	holdings.emplace_back(make_unique<Stock>("JPM", "JPMorgan Chase & Co."));	//adds a stock to the holdings vector

	holdings.emplace_back(make_unique<ETF>("SPY", "S&P 500 ETF"));		//adds an ETF to the holdings vector
	holdings.emplace_back(make_unique<ETF>("QQQ", "Nasdaq-100 ETF"));	//adds an ETF to the holdings vector
	holdings.emplace_back(make_unique<ETF>("IWM", "Russell 2000 ETF"));	//adds an ETF to the holdings vector
	holdings.emplace_back(make_unique<ETF>("VTI", "Vanguard Total Stock Market ETF")); //adds an ETF to the holdings vector

	//mutual funds can be added here if desired
	//holdings.emplace_back(make_unique<MutualFund>("VTSAX", "Vanguard Total Stock Market Index Fund")); //adds a mutual fund to the holdings vector
	//holdings.emplace_back(make_unique<MutualFund>("VFIAX", "Vanguard 500 Index Fund")); //adds a mutual fund to the holdings vector
	//however the finnhub API does not support mutual funds in the free tier, so this is commented out

	int numStocks = holdings.size();			//number of stocks in the portfolio
	int iterations = 1;				//tracks how many times the program has updated stock prices

	while (true) {							//while loop contains the rest of the logic, ensure the continuous refreshing of stock prices


		for (const auto &security : holdings)				//initialize the map, pairing a stock's symbol with its price
			security->updatePrice();

		
		system("clear");		//clears display
		int count = 0;			//used to format stock and price layout
	

		for (const auto &security : holdings) {				//traverse the map, stockPrices 				
			security->displayInfo(); 				//display information for each stock, ETF, or mutual fund

			count++; 			//formats display to allow 4 stocks per line
			if (count%4 == 0) {
				cout<<endl; 
				cout<<endl;
			}			
		}
	

		cout<<endl; 
		cout<<endl; 

		
		cout<<"Iteration #" << iterations <<endl; 		//tracks how many times the program has updated stock prices 
		iterations++;


		cout<<"Updating data in 120 seconds..."<<endl; 		//stock prices are refreshed every 120 seconds 
		sleep_for(seconds(120)); 					//program sleeps for 120 seconds before moving to the next iteration 
	}
				
			
	cout<<endl; 

return 0; 
} 





