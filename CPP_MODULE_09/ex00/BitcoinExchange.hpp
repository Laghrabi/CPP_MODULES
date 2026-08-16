

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> _exchangeRates;

        bool isOnlyDigits(const std::string& str) const;
        bool isDouble(const std::string& input) const;

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& databaseFile);
        void processInput(const std::string& inputFile);
};

#endif