#include "stocks.h"

//constructor
Stock::Stock (string sym, string nm) : Security(sym, nm){ 
	updateData(); //initialize open and previous close prices
} 




//displays a stocks information 
void Stock::displayInfo() const { 

	updatePrice(); //updates stock data before displaying
	if (getCurrentPrice() > getHigh()) {
		high = getCurrentPrice(); //update high if current price is greater than previous high
	}
	if (getCurrentPrice() < getLow()) {
		low = getCurrentPrice(); //update low if current price is less than previous low
	}

	if (previousPrice == 0.0) {
		cout << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
		     << " | H: " << setw(7) << fixed << setprecision(2) << high 
		     << " | L: " << setw(7) << fixed << setprecision(2) << low 
		     << " | O: " << setw(7) << fixed << setprecision(2) << open 
		     << " | PC: " << setw(6) << fixed << setprecision(2) << prevClose << endl; 
	}
	else if (currentPrice > previousPrice) {
		cout << "\033[32m" << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
		     << " | H: " << setw(7) << fixed << setprecision(2) << high 
		     << " | L: " << setw(7) << fixed << setprecision(2) << low 
		     << " | O: " << setw(7) << fixed << setprecision(2) << open 
		     << " | PC: " << setw(6) << fixed << setprecision(2) << prevClose << "\033[0m" << endl; 
	}
	else if (currentPrice < previousPrice) {
		cout << "\033[31m" << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
		     << " | H: " << setw(7) << fixed << setprecision(2) << high 
		     << " | L: " << setw(7) << fixed << setprecision(2) << low 
		     << " | O: " << setw(7) << fixed << setprecision(2) << open 
		     << " | PC: " << setw(6) << fixed << setprecision(2) << prevClose << "\033[0m" << endl; 
	}
	else {
		cout << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
		     << " | H: " << setw(7) << fixed << setprecision(2) << high 
		     << " | L: " << setw(7) << fixed << setprecision(2) << low 
		     << " | O: " << setw(7) << fixed << setprecision(2) << open 
		     << " | PC: " << setw(6) << fixed << setprecision(2) << prevClose << endl; 
	}
}; 





void Stock::updateData() const { //updates open and previous close prices
		CURL* curl;
		CURLcode result;
		string readBuffer;

		string url = "https://finnhub.io/api/v1/quote?symbol=" + symbol + "&token=" + API;
		
		curl = curl_easy_init();

		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
			result = curl_easy_perform(curl);
			curl_easy_cleanup(curl);

			if (result != CURLE_OK) {
				cerr << "Failed to fetch data" << endl;
				return;
			}
		}

		Json::Reader reader;
		Json::Value jsonData;

		if (reader.parse(readBuffer, jsonData)) {
			open = jsonData["o"].asDouble();
			prevClose = jsonData["pc"].asDouble();
			high = jsonData["h"].asDouble();
			low = jsonData["l"].asDouble();
		}
};



double Stock::getHigh() const { return high; };

double Stock::getLow() const { return low; };

double Stock::getOpen() const { return open; };

double Stock::getPrevClose() const { return prevClose; };












