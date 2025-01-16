#pragma once

#include <vector>
#include "OrderBookEntry.h"


class MainApp
{
    public:
        MainApp();
        void init();
    
    private:
        void loadOrderBook();
        void displayMenu();
        void displayHelp();
        void displayExchangeStats();
        void enterOffer();
        void enterBid();
        void displayWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int choice);
        std::vector<OrderBookEntry> orders;

};