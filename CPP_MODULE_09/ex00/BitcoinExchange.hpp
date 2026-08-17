/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:14:56 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/19 18:14:58 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> _exchangeRates;

        bool isOnlyDigits(const std::string& str) const;
        bool isDouble(const std::string& input) const;
        bool isValidDate(const std::string& date) const;

    public:

        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase(const std::string& databaseFile);
        void processInput(const std::string& inputFile);
};

#endif