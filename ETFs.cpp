#include "ETFs.h"

//constructor
ETF::ETF(string sym, string nm) : Security(sym, nm), expenseRatio(0.0) {}

void ETF::setExpenseRatio() { 

    CURL* curl; 
    CURLcode result; 
    string readBuffer;

    string url = "https://finnhub.io/api/v1/etf/profile?symbol=" + symbol + "&token=" + API;

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
        this->expenseRatio = jsonData["expenseRatio"].asDouble();
    }
}

double ETF::getExpenseRatio() const {
    return expenseRatio;
}

void ETF::displayInfo() const {

    cout << getSymbol() << ": " << " @ " << getPrice() << " | Expense Ratio: " << getExpenseRatio() << "%" << endl;
};

