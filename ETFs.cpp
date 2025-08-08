#include "ETFs.h"

//constructor
//uses security class to initialize ETF object and leaves expenseRatio at 0.0 to be updated later
ETF::ETF(string sym, string nm) : Security(sym, nm){
    updateData();
}

//sets the expense ratio of the ETF by fetching data from the API
void ETF::updateData() const { 
    // Hard-coded expense ratios since ETF endpoints require paid Finnhub plan
    if (symbol == "SPY") {
        expenseRatio = 0.09;  // 0.09% for SPDR S&P 500
    } else if (symbol == "QQQ") {
        expenseRatio = 0.20;  // 0.20% for Invesco QQQ
    } else if (symbol == "IWM") {
        expenseRatio = 0.19;  // 0.19% for iShares Russell 2000
    } else if (symbol == "VTI") {
        expenseRatio = 0.03;  // 0.03% for Vanguard Total Stock Market
    }
};
//returns the expense ratio of the ETF
double ETF::getExpenseRatio() const {
    return expenseRatio;
}


//displays the ETF information including symbol, price, and expense ratio
void ETF::displayInfo() const {

    if (previousPrice == 0.0) {
        cout << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << endl;
    }
    else if (currentPrice > previousPrice) {
        cout << "\033[32m" << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << "\033[0m" << endl;
    } 
    else if (currentPrice < previousPrice) {
        cout << "\033[31m" << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << "\033[0m" << endl;
    }
    else {
        cout << setw(8) << right << getSymbol() << ": @ " << setw(8) << fixed << setprecision(2) << getCurrentPrice() 
             << " | Expense Ratio: " << setw(5) << fixed << setprecision(2) << getExpenseRatio() << "%" << endl;
    }
};