g++ smTracker.cpp securities.cpp stocks.cpp ETFs.cpp MutualFunds.cpp\
    -std=c++17 \
    $(pkg-config --cflags --libs libcurl jsoncpp) \
    -o smTracker
