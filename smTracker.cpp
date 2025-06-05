#include <iostream>		//needed for input/output
#include <string> 		//needed for dealing with strings
#include <map>			//needed for map usage
#include <iomanip> 		//needed for formatting 
#include <cstdlib>		//needed for system calls 
#include <chrono>		//needed for time
#include <thread>		//needed for sleep
#include <vector>

#include "stocks.h"

using namespace std;			//simplicity 
using namespace std::this_thread; 	//sleep
using namespace std::chrono;		//time 





int main() { 
	
	//variables 
	int numStocks = 4; 											//number of stocks being tracked
	int iterations = 1; 											//tracks the number of times the program updates stock prices 

	
	map<string, double> stockPrices; 									//map pairing stock symbols to their respective prices 
	map<string, double> previousStockPrices; 								//map tracking the previous prices of stocks 


	vector<string> stockSymbols = {"AAPL","NVDA", "MSFT" , "SPY"};						//vector containing stock symbols
	vector<string> stockNames = {"Apple", "Nvidia", "Microsoft", "S&P 500"};				//vector containg stock names 
	vector<unique_ptr<Security>> holdings;									//vector of security types 



	for (int i=0; i<numStocks; i++)										//fills up vector with stock objects 
		holdings.emplace_back(make_unique<Stock>(stockSymbols[i], stockNames[i])); 
	



	while (true) {							//while loop contains the rest of the logic, ensure the continuous refreshing of stock prices 


		for (int i=0; i<numStocks; i++)				//initialize the map, pairing a stock's symbol with its price
			stockPrices[stockNames[i]] = holdings[i]->getPrice(); 
		

		
		system("clear");		//clears display
		int count = 0;			//used to format stock and price layout
	

		if (iterations > 1) {		//after the 1st iteration 

			for (const auto &stocks : stockPrices) {				//traverse the map, stockPrices
			
				double prevPrice = previousStockPrices[stocks.first];  		//set previous price of stock
				double diff = stocks.second - prevPrice; 			//change in price
				
				if (stocks.second > prevPrice) {														//if price increased 
					cout<< "\033[32m" << setw(8) << stocks.first << ": $" << stocks.second << setw(5) << " δ" << diff << setw(10) << " " << "\033[0m";	//green text color
				} 
				else if (stocks.second < prevPrice) { 														//if price decreased
					cout<< "\033[31m" << setw(8) << stocks.first << ": $" << stocks.second << setw(5) << " δ" << diff << setw(10) << " " << "\033[0m";	//output red text color
				}
				else {																		//if price is unchanged
					cout<< setw(8) << stocks.first << ": $"<< stocks.second << setw(5) << " δ" << diff << setw(10) << " ";					//output default color
				}



				count++;			//formats display to allow 4 stocks per line
				if (count%4 == 0) { 
					cout<<endl;
					cout<<endl;
				}
			}
		} 
		else { 				//for the 1st iteration
		
			for (const auto &stocks : stockPrices) {				//traverse the map, stockPrices 
				
				cout<< setw(8) << stocks.first << ": $"<< stocks.second << setw(2) << " "; 	//output stocks and prices
				


				count++; 			//formats display to allow 4 stocks per line
				if (count%4 == 0) {
					cout<<endl; 
					cout<<endl;
				}
			}
		}
	

		cout<<endl; 
		cout<<endl; 

	
		previousStockPrices = stockPrices; 			//set previousStock prices equal to current stockPrice to track prices for the next iteration

		cout<<"Iteration #" << iterations <<endl; 		//tracks how many times the program has updated stock prices 
		iterations++;

		
		cout<<"Updating data in 9 seconds..."<<endl; 		//stock prices are refreshed every 9 seconds 
		sleep_for(seconds(9)); 					//program sleeps for 9 seconds before moving to the next iteration 
	}
				
			
	cout<<endl; 

return 0; 
} 





