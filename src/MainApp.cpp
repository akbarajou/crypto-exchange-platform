#include <iostream>
#include <vector>
#include "MainApp.h"
#include "FileReader.h"


MainApp::MainApp()
{
    std::cout << "Welcome to the Crypto Exchange Platform." << '\n';
}

void MainApp::init()
{
    int choice;
    loadOrderBook();
    while (true)
    {
        displayMenu();
        choice = getUserOption();
        processUserOption(choice);
        std::cout << '\n';
    }    
}

void MainApp::loadOrderBook()
{
    orders = FileReader::readCSV("../data/20200317.csv");
}

void MainApp::displayMenu()
{
    std::cout << "1: Help." << '\n';
    std::cout << "2: Exchange Stats." << '\n';
    std::cout << "3: Make an Offer." << '\n';
    std::cout << "4: Make a Bid." << '\n';
    std::cout << "5: Wallet." << '\n';
    std::cout << "6: Continue." << '\n';
    std::cout << "===================" << '\n';
    std::cout << "Enter your choice: ";
}

void MainApp::displayHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make offers and bids to make money." << '\n';
}

void MainApp::displayExchangeStats()
{
    std::cout << "Exchange Stats - display the current exchange stats." << '\n';
    std::cout << "Entries: " << orders.size() << '\n';

    unsigned int bids = 0;
    unsigned int asks = 0;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == OrderBookType::ask)
        {
            asks++;
        }
        if (e.orderType == OrderBookType::bid)
        {
            bids++;
        }
    }

    std::cout << "OrderBook ASKs: " << asks << "\tBIDs: " << bids << '\n';
}

void MainApp::enterOffer()
{
    std::cout << "Mark and offer - enter the amount" << '\n';
}

void MainApp::enterBid()
{
    std::cout << "Make a bid - enter the amount" << '\n';
}

void MainApp::displayWallet()
{
    std::cout << "Wallet - display your current wallet." << '\n';
}

void MainApp::gotoNextTimeFrame()
{
    std::cout << "Continue - go to the next time frame." << '\n';
}


int MainApp::getUserOption()
{
    int choice;
    std::cin >> choice;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        choice = -1;
    }

    return choice;
}

void MainApp::processUserOption(int choice)
{
    switch(choice)
    {
        case 1:
            displayHelp();
            break;
        case 2:
            displayExchangeStats();
            break;
        case 3:
            enterOffer();
            break;
        case 4:
            enterBid();
            break;
        case 5:
            displayWallet();
            break;
        case 6:
            gotoNextTimeFrame();
            break;
        default:
            std::cout << "Invalid choice. Choose 1-6." << '\n';
            break;
    }
}