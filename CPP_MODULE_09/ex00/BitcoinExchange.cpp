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
    for (int i = 0; i < str.length(); ++i) {
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

        if (rowDate.length() != 10 || rowDate[4] != '-' || rowDate[7] != '-') {
            std::cerr << "Error: bad input => " << rowDate << std::endl;
            continue ;
        }

        std::string yearStr = rowDate.substr(0, 4);
        std::string monthStr = rowDate.substr(5, 2);
        std::string dayStr = rowDate.substr(8, 2);

        if (!isOnlyDigits(yearStr) || !isOnlyDigits(monthStr) || !isOnlyDigits(dayStr)) {
            std::cerr << "Error: bad input => " << rowDate << std::endl;
            continue ;
        }

        int year, month, day;
        std::istringstream(yearStr) >> year;
        std::istringstream(monthStr) >> month;
        std::istringstream(dayStr) >> day;

        if (year < 2009) {
            std::cerr << "Error: bad input => " << rowDate << std::endl;
            continue ;
        }

        if (month < 1 || month > 12 || day < 1 || day > 31) {
            std::cerr << "Error: bad input => " << rowDate << std::endl;
            continue ;
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
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

        // TODO: If you reach this point, all validation has passed. 
        // Search your std::map for rowDate, do the math, and print the result!
    }
}
