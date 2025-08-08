#include "ETFs.h"

//constructor
//uses security class to initialize ETF object and leaves expenseRatio at 0.0 to be updated later
ETF::ETF(string sym, string nm) : Security(sym, nm){
    updateData();
}

//sets the expense ratio of the ETF by fetching data from the API
void ETF::updateData() const { 

    CURL* curl; 
    CURLcode result; 
    string readBuffer;

    string url = "https://finnhub.io/api/v1/etf/metric?symbol=" + symbol + "&token=" + API;

    curl = curl_easy_init(); 

    if (curl) { 
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        result = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (result != CURLE_OK) {
            cerr << "Failed to fetch ETF expense ratio" << endl;
            return; 
        }
    }

    Json::Reader reader;
    Json::Value jsonData;

    if (reader.parse(readBuffer, jsonData)) {
        expenseRatio = jsonData["metric.expenseRatio"].asDouble();
        netAssets = jsonData["metric.netAssets"].asDouble();
    }
}


//returns the expense ratio of the ETF
double ETF::getExpenseRatio() const {
    return expenseRatio;
}


//displays the ETF information including symbol, price, and expense ratio
void ETF::displayInfo() const {

    if (previousPrice == 0.0) {
        cout << setw(8) << getSymbol() << ": " << " @ " << getCurrentPrice() << " | Expense Ratio: " << getExpenseRatio() << "%" << setw(10) << " " << endl;
    }
    else if (currentPrice > previousPrice) {
        cout << "\033[32m" << setw(8) << getSymbol() << ": " << " @ " << getCurrentPrice() << " | Expense Ratio: " << getExpenseRatio() << "%" << setw(10) << " " << "\033[0m" << endl;
    } 
    else if (currentPrice < previousPrice) {
        cout << "\033[31m" << setw(8) << getSymbol() << ": " << " @ " << getCurrentPrice() << " | Expense Ratio: " << getExpenseRatio() << "%" << setw(10) << " " << "\033[0m" << endl;
    }
    else {
        cout << setw(8) << getSymbol() << ": " << " @ " << getCurrentPrice() << " | Expense Ratio: " << getExpenseRatio() << "%" << setw(10) << " " << endl;
    }
};