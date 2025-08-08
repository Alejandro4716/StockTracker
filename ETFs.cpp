#include "ETFs.h"

//constructor
//uses security class to initialize ETF object and leaves expenseRatio at 0.0 to be updated later
ETF::ETF(string sym, string nm) : Security(sym, nm){
    updateData();
}



//displays the ETF information including symbol, price, and expense ratio
void ETF::displayInfo() const {

    if (previousPrice == 0.0) {
        cout << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << setw(5) << getNAVPS() << setw(5) << getAUM() << endl;
    }
    else if (currentPrice > previousPrice) {
        cout << "\033[32m" << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << setw(5) << getNAVPS() << setw(5) << getAUM() << "\033[0m" << endl;
    } 
    else if (currentPrice < previousPrice) {
        cout << "\033[31m" << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << setw(5) << getNAVPS() << setw(5) << getAUM() << "\033[0m" << endl;
    }
    else {
        cout << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << setw(5) << getNAVPS() << setw(5) << getAUM() << endl;
    }
};






//sets the expense ratio of the ETF by fetching data from the API
void ETF::updateData() const { 
    // Hard-coded expense ratios since ETF endpoints require paid Finnhub plan
    if (symbol == "SPY") {
        expenseRatio = 0.09;  // 0.09% for SPDR S&P 500
        NAVPS = 621.90;  // Example NAVPS for SPY
        AUM = 637.14;  // Example AUM for SPY
    } else if (symbol == "QQQ") {
        expenseRatio = 0.20;  // 0.20% for Invesco QQQ
        NAVPS = 561.23;  // Example NAVPS for QQQ
        AUM = 360.63;  // Example AUM for QQQ
    } else if (symbol == "IWM") {
        expenseRatio = 0.19;  // 0.19% for iShares Russell 2000
        NAVPS = 202.88; // Example NAVPS for IWM
        AUM = 62.45; // Example AUM for IWM
    } else if (symbol == "VTI") {
        expenseRatio = 0.03;  // 0.03% for Vanguard Total Stock Market
        NAVPS = 310.90; // Example NAVPS for VTI
        AUM = 502.10; // Example AUM for VTI
    }
};


//returns the expense ratio of the ETF
double ETF::getExpenseRatio() const { return expenseRatio; }

//returns the NAVPS of the ETF
double ETF::getNAVPS() const { return NAVPS; }

//returns the AUM of the ETF
double ETF::getAUM() const { return AUM;}