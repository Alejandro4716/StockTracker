#include "stocks.h"



//consturctor
Stock::Stock (string sym, string nm) : Security(sym, nm){} 


/*
void Stock::getMetrics() { 


	CURL* curl; 
	CURLcode result; 
	string readBuffer; 

	string url = "https://finnhub.io/api/v1/stock/metric?symbol=" + ticker + "&metric=all&token=" +API;

	curl = curl_easy+init(); 

	if (curl) { 
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        	result = curl_easy_perform(curl);
        	curl_easy_cleanup(curl);
	

		if (result != CURLE_OK) {
			cerr << "Failed to fetch stock metrics" <<endl;
			return; 
		}
	}


	Json::Reader reader; 
	Json::Value jsonData; 


	if (reader.parse(readBuffer, jsonData)) { 
		Json::value metrics = jsonData["metric"]; 
		this->dividendYield = metrics["dividendYieldIndicatedAnnual"].asDouble();
		this->eps = metrics["epsInclExtraItemsTTM"].asDouble();
		this->marketCap = metrics["marketCapitalization"].asDouble();
	}
};
*/


//displays a stocks information 
void Stock::displayInfo() const { 

	cout << getSymbol() << ": " << " @ " << getPrice() <<endl; 
}; 


























