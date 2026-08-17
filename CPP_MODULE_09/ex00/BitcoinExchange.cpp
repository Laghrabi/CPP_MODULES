/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:14:45 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/19 18:14:48 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isOnlyDigits(const std::string& str) const {
    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); ++i) {
        if (!(std::isdigit(static_cast<unsigned char>(str[i]))))
            return (false);
    }
    return (true);
}

bool BitcoinExchange::isDouble(const std::string& input) const {
    int     dot = 0;
    size_t  i = 0;
    size_t  len = input.length();

    while (i < len)
    {
        if (dot == 0 && input[i] == '.' && i != 0 && i + 1 != len)
            dot = 1;
        else if (isdigit(input[i]) == 0)
            return (false);
        i++;
    }
    if (dot == 0)
        return (false);
    return (true);
}

bool BitcoinExchange::isValidDate(const std::string& date) const {

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    if (!isOnlyDigits(yearStr) || !isOnlyDigits(monthStr) || !isOnlyDigits(dayStr))
        return (false);

    int year, month, day;
    std::istringstream(yearStr) >> year;
    std::istringstream(monthStr) >> month;
    std::istringstream(dayStr) >> day;

    if (year < 2009)
        return (false);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);

    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29)
            return false;
        if (!isLeapYear && day > 28)
            return false;
    }

    return (true);
}

void BitcoinExchange::processInput(const std::string& inputFile) {
    std::ifstream dbFile(inputFile.c_str());

    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;

    if (getline(dbFile, line)) {
        std::istringstream iss(line);
        std::string date, del, value, leftOvers;

        if (!(iss >> date >> del >> value) || date != "date" || del != "|" || value != "value" || (iss >> leftOvers)) {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    while (getline(dbFile, line)) {
        if (line.empty()) {
            continue ;
        }

        std::istringstream lineStream(line);
        std::string rowDate, rowDel, rowValue, leftOvers;

        if (!(lineStream >> rowDate >> rowDel >> rowValue) || (lineStream >> leftOvers) || rowDel != "|") {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }

        if (!isValidDate(rowDate)) {
            std::cerr << "Error: bad input => " << rowDate << std::endl;
            continue ;
        }

        if (rowValue[0] == '-') {
            std::cerr << "Error: not a positive number." << std::endl;
            continue ;
        }
        
        if (!isOnlyDigits(rowValue) && !isDouble(rowValue)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        
        float val;
        std::istringstream valStream(rowValue);
        valStream >> val;
        
        if (val > 1000.0f) {
            std::cerr << "Error: too large a number." << std::endl;
            continue ;
        }

        std::map<std::string, double>::iterator it = _exchangeRates.lower_bound(rowDate);

        if (it == _exchangeRates.end() || it->first != rowDate) {
            if (it == _exchangeRates.begin()) {
                std::cerr << "Error: date is older than database records => " << rowDate << std::endl;
                continue ;
            }
            --it;
        }
        std::cout << rowDate << " => " << val << " = " << (val * it->second) << std::endl;
    }
}

void BitcoinExchange::loadDatabase(const std::string& databaseFile) {

    std::ifstream db(databaseFile.c_str());

    if (!db.is_open()) {
        std::cerr << "Error: could not open database file: " << databaseFile << std::endl;
        return ; 
    }

    std::string line;
    getline(db, line);

    while (getline(db, line)) {
        if (line.empty()) {
            continue ;
        }

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            std::cerr << "Error: invalid database format => " << line << std::endl;
            continue ;
        }

        std::string dbDate = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);

        if (!isValidDate(dbDate))
            continue ;

        float rate;
        std::istringstream rateStream(rateStr);
        if (!(rateStream >> rate)) {
            continue ;
        }

        _exchangeRates[dbDate] = rate;
    }
}