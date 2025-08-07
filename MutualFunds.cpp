/*              logic works however finhub's free tier does not support mutual funds, so this is commented out


#include "MutualFunds.h"


//constructor
//uses security class to initialize MutualFund object and leaves NAV at 0.0 to be updated later
MutualFund::MutualFund(string sym, string nm) : Security(sym, nm), NAV(0.0) {}


//sets the NAV of the Mutual Fund by fetching data from the API
void MutualFund::setNAV() {
    CURL* curl;
    CURLcode result;
    string readBuffer;

    string url = "https://finnhub.io/api/v1/mutualfund/profile?symbol=" + symbol + "&token=" + API;

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        result = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (result != CURLE_OK) {
            cerr << "Failed to fetch mutual fund minimum purchase amount" << endl;
            return;
        }
    }

    Json::Reader reader;
    Json::Value jsonData;

    if (reader.parse(readBuffer, jsonData)) {
        this->NAV = jsonData["nav"].asDouble();
    }
}


//returns the NAV of the Mutual Fund
double MutualFund::getNAV() const {
    return NAV;
}

//displays the Mutual Fund information including symbol, price, and NAV
void MutualFund::displayInfo() const { 
        cout << getSymbol() << ": " << " @ " << getPrice() << " | NAV: " << getNAV() << "%" << endl;
}

*/