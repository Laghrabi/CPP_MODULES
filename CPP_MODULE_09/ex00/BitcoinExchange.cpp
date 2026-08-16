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

void BitcoinExchange::printError(const std::string message, std::ifstream& file, bool close) const {
    std::cerr << "Error: bad input => " << message << std::endl;
    if (close)
        file.close();
}

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
        printError("Error: could not open file.", dbFile, false);
        return ;
    }

    std::string date, value, del, line, leftOvers;

    getline(dbFile, line);
    std::istringstream iss(line);

    if (!(iss >> date >> del >> value)) {
        printError("Error: bad input => ", dbFile, true);
        return ;
    } else {
        if (date != "date" || del != "|" || value != "value") {
            printError("Error: bad input => ", dbFile, true);
            return ;
        }
    }

    if((iss >> leftOvers)) {
        printError("Error: bad input => ", dbFile, true);
        return ;
    }

    while (getline(dbFile, line)) {
        if (line.empty()) {
            continue ;
        }

        std::istringstream lineStream(line);
        std::string rowDate, rowDel, rowValue;

        if (!(lineStream >> rowDate >> rowDel >> rowValue)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }

        if (rowDate.length() != 10 || rowDate[4] != '-' || rowDate[7] != '-') {
            printError("Error: bad input => ", dbFile, false);
            continue ;
}

        std::string year, month, day;
        year = rowDate.substr(0, 4);
        month = rowDate.substr(5, 2);
        day = rowDate.substr(8, 2);
        if (!isOnlyDigits(year) || !isOnlyDigits(month) || !isOnlyDigits(day) ||
            rowDel != "|" || (!isOnlyDigits(rowValue) && !isDouble(rowValue))) {
                printError("Error: bad input => ", dbFile, false);
                continue ;
        }
    }
}

