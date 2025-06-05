#include "securities.h"
#include <curl/curl.h>          //needed for making API requests
#include <json/json.h>          //needed for parsing JSON responses 


size_t WriteCallback (void* contents, size_t size, size_t nmemb, string* output) {      //function to handle API responses 
         //contents : pointer to response data
         //size : size of memory blocks received 
         //nmemb : number of memory blocks received 
         output->append((char*)contents, size * nmemb);          //adds data to output string
         return size * nmemb;                                    //returns total size of data received 
};





//constructor logic 
Security::Security(string sym, string nm) {

	symbol = sym; 
	name = nm; 
	updatePrice(); 
}; 




//deconstructor
Security::~Security() = default; 



//getter functions 
string Security::getSymbol() const { return symbol; };

string Security::getName() const { return name; };

double Security::getValue(double qty) const { return qty * getPrice(); };

double Security::getPrice() const { 
	updatePrice(); 
	return currentPrice;
};





void Security::updatePrice () const {                   //retrieves stock price for a given stock

        CURL* curl;                     //creates cURL object to handle API call
        CURLcode result;                //stores result of the API call (success or failure)
        string readBuffer;              //stores the API response in JSON format

        string url = "https://finnhub.io/api/v1/quote?symbol=" + symbol + "&token=" + API; 


        curl = curl_easy_init();        //initialize a cURL session 

        if (curl) { 
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());                       //set API url
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);           //set callback function 
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);                 //store response in buffer
                result = curl_easy_perform(curl);                                       //execute request
                curl_easy_cleanup(curl);                                                //clean up

                if (result != CURLE_OK) {
                        cerr<<"Failed to fetch data"<<endl; 
                        return; 
                } 
        }


        Json::Reader reader;            //creates a json parser  
        Json::Value jsonData;           //holds parsed json data

        if (reader.parse(readBuffer, jsonData)) {                                               //converts json string into an object
                currentPrice =  jsonData["c"].asDouble();                                                //returns price as double
        } 
};
