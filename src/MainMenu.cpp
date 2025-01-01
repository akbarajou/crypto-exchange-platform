#include <iostream>
#include <vector>
#include "MainMenu.h"


MainMenu::MainMenu()
{
    std::cout << "Welcome to the Crypto Exchange Platform." << '\n';
}

void MainMenu::init()
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

void MainMenu::loadOrderBook()
{
    std::cout << "Loading order book..." << '\n';
    
    OrderBookEntry order1{1000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::BID};
    OrderBookEntry order2{2000, 0.02, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::BID};

    orders.push_back(order1);
    orders.push_back(order2);

    std::cout << "Order book loaded." << " Size: " << orders.size() << '\n';
}

void MainMenu::displayMenu()
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

void MainMenu::displayHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make offers and bids to make money." << '\n';
}

void MainMenu::displayExchangeStats()
{
    std::cout << "Exchange Stats - display the current exchange stats." << '\n';
    std::cout << "Entries: " << orders.size() << '\n';
}

void MainMenu::enterOffer()
{
    std::cout << "Mark and offer - enter the amount" << '\n';
}

void MainMenu::enterBid()
{
    std::cout << "Make a bid - enter the amount" << '\n';
}

void MainMenu::displayWallet()
{
    std::cout << "Wallet - display your current wallet." << '\n';
}

void MainMenu::gotoNextTimeFrame()
{
    std::cout << "Continue - go to the next time frame." << '\n';
}


int MainMenu::getUserOption()
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

void MainMenu::processUserOption(int choice)
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