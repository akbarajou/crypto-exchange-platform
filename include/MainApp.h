#pragma once

#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"


class MainApp
{
public:
    MainApp();
    void init();

private:
    void displayMenu();
    void displayHelp();
    void displayExchangeStats();
    void enterAsk();
    void enterBid();
    void displayWallet();
    void gotoNextTimeFrame();
    int getUserOption();
    void processUserOption(int choice);
    void displayStatisticsForType(const std::string& product,
                                  OrderBookType type,
                                  const std::string& typeName);

    std::string currentTime;

    OrderBook orderBook{"../data/20200317.csv"};
    // OrderBook orderBook{"../data/test.csv"};

    Wallet wallet;

};