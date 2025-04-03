#include <iostream>		//needed for input/output
#include <string> 		//needed for dealing with strings
#include <curl/curl.h>		//needed for making API requests
#include <json/json.h> 		//needed for parsing JSON responses 
#include <map>			//needed for map usage
#include <iomanip> 		//needed for formatting 
#include <cstdlib>		//needed for system calls 
#include <chrono>		//needed for time
#include <thread>		//needed for sleep


using namespace std;			//simplicity 
using namespace std::this_thread; 	//sleep
using namespace std::chrono;		//time 





const string API = "cvh1j41r01qi76d5vvcgcvh1j41r01qi76d5vvd0";		//API key for finnhub data





size_t WriteCallback (void* contents, size_t size, size_t nmemb, string* output) {		//function to handle API responses 

	//contents : pointer to response data
	//size : size of memory blocks received 
	//nmemb : number of memory blocks received 
	
	
	output->append((char*)contents, size * nmemb); 		//adds data to output string
	return size * nmemb; 					//returns total size of data received 
};






double getStockPrice (const string& symbol) {			//retrieves stock price for a given stock

	CURL* curl; 			//creates cURL object to handle API call
	CURLcode result; 		//stores result of the API call (success or failure)
	string readBuffer; 		//stores the API response in JSON format

	string url = "https://finnhub.io/api/v1/quote?symbol=" + symbol + "&token=" + API; 


	curl = curl_easy_init(); 	//initialize a cURL session 

	if (curl) { 
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); 			//set API url
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);		//set callback function 
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer); 		//store response in buffer
		result = curl_easy_perform(curl); 					//execute request 
		curl_easy_cleanup(curl); 						//clean up

		if (result != CURLE_OK) {
			cerr<<"Failed to fetch data"<<endl; 
			return -1; 
		} 
	}


	Json::Reader reader;		//creates a json parser  
	Json::Value jsonData; 		//holds parsed json data

	if (reader.parse(readBuffer, jsonData)) { 						//converts json string into an object
		string priceStr = jsonData["c"].asString();					//extracts stock price from json data
		return priceStr.empty() ? -1 : stod(priceStr); 					//converts price into a double
												// if price is missing return -1
	} 

return 0.00;
};







int main() { 
	
	//variables 
	int numStocks = 8; 											//number of stocks being tracked
	int iterations = 1; 											//tracks the number of times the program updates stock prices 
	
	map<string, double> stockPrices; 									//map pairing stock symbols to their respective prices 
	map<string, double> previousStockPrices; 								//map tracking the previous prices of stocks 

	vector<string> stockSymbols = {"AAPL","NVDA", "AMZN", "COST", "MSFT" , "JPM", "CRWD", "SPY"};		//vector contain stock symbols being tracked 


	while (true) {							//while loop contains the rest of the logic, ensure the continuous refreshing of stock prices 


		for (int i=0; i<numStocks; i++) { 				//initialize the map, pairing a stock's symbol with its price
			double price = getStockPrice(stockSymbols[i]);		//sets stock price  
			stockPrices[stockSymbols[i]] = price; 			//pairs price to symbol
		}

		
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





