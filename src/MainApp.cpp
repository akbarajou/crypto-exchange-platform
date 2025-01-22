#include <iostream>
#include <vector>
#include <limits>
#include "MainApp.h"
#include "OrderBook.h"
#include "OrderBookEntry.h"
#include "FileReader.h"



MainApp::MainApp()
{
    std::cout << "Welcome to the Crypto Exchange Platform." << '\n';
}

void MainApp::init()
{
    currentTime = orderBook.getEarliestTime();
    int choice;
    while (true)
    {
        displayMenu();
        choice = getUserOption();
        processUserOption(choice);
        std::cout << '\n';
    }    
}


void MainApp::displayMenu()
{
    std::cout << "1: Help." << '\n';
    std::cout << "2: Exchange Stats." << '\n';
    std::cout << "3: Make an Ask." << '\n';
    std::cout << "4: Make a Bid." << '\n';
    std::cout << "5: Wallet." << '\n';
    std::cout << "6: Continue." << '\n';
    std::cout << "===================\t Current time: " << currentTime << '\n';
    std::cout << "Enter your choice: ";
}

void MainApp::displayHelp()
{
    std::cout << "Help - your aim is to make money.\nAnalyze the market and make offers and bids to make money." << '\n';
}

void MainApp::displayExchangeStats()
{
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << '\t';
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << '\t';
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << '\t';
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << '\n';
    }
}

void MainApp::enterAsk()
{
    std::cout << "Make an Ask - enter the amount: product, price, amount\ne.g  ETH/BTC,100,0.5\n>>";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = FileReader::tokenise(input, ',');

    if (tokens.size() != 3)
    {
        std::cout << "MainApp::enterAsk - Bad input!" << input << '\n';
    }
    else
    {
        try
        {
            OrderBookEntry obe = FileReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask
            );
            orderBook.insertOrder(obe);
        }
        catch (const std::exception& e)
        {
            std::cerr << "MainApp::enterAsk - Bad input: " << e.what() << '\n';
        }    
    }

    std::cout << "You typed: " << input << '\n';
}

void MainApp::enterBid()
{
    std::cout << "Make a bid - enter the amount: product, price, amount\ne.g  ETH/BTC,100,0.5\n>>";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = FileReader::tokenise(input, ',');

    if (tokens.size() != 3)
    {
        std::cout << "MainApp::enterBid - Bad input!" << input << '\n';
    }
    else
    {
        try
        {
            OrderBookEntry obe = FileReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid
            );
            orderBook.insertOrder(obe);
        }
        catch (const std::exception& e)
        {
            std::cerr << "MainApp::enterBid - Bad input: " << e.what() << '\n';
        }    
    }

    std::cout << "You typed: " << input << '\n';
}

void MainApp::displayWallet()
{
    std::cout << "Wallet - display your current wallet." << '\n';
}

void MainApp::gotoNextTimeFrame()
{
    std::cout << "Continue - go to the next time frame." << '\n';
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << '\n';
    for (OrderBookEntry& sale : sales)
    {
        std::cout << "Sale price: " << sale.price << "\t amount: " << sale.amount << '\n';
    }
    currentTime =orderBook.getNextTime(currentTime);
}


int MainApp::getUserOption()
{
    int choice = 0;
    std::string line;

    std::getline(std::cin, line);
    
    try
    {
        choice = std::stoi(line);
    }
    catch (const std::exception& e)
    {
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
            enterAsk();
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