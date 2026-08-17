/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 10:56:11 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/15 14:48:39 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    std::cout << "--- 1. Mandatory Subject Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- 2. Exception Test: Capacity Exceeded ---" << std::endl;
    try {
        Span sp = Span(2);
        sp.addNumber(10);
        sp.addNumber(20);
        std::cout << "Adding 3rd number to a Span of size 2..." << std::endl;
        sp.addNumber(30);
    } catch (std::exception& e) {
        std::cerr << "Caught successfully: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. Exception Test: Not Enough Elements ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << "Trying to find span with only 1 number..." << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Caught successfully: " << e.what() << std::endl;
    }

    std::cout << "\n--- 4. The 10,000 Numbers & Iterator Range Test ---" << std::endl;
    try {
        Span sp = Span(10000);
        std::vector<int> randomNumbers;
        
        srand(time(NULL)); 
        
        for (int i = 0; i < 10000; i++) {
            randomNumbers.push_back(rand());
        }
        
        sp.addNumbers(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Successfully added 10,000 numbers using iterators." << std::endl;
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
