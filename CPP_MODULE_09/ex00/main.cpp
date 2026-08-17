/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:05:37 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/19 17:06:03 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }

    BitcoinExchange btcEngine;

    btcEngine.loadDatabase("data.csv");
    btcEngine.processInput(argv[1]);

    return (0);
}