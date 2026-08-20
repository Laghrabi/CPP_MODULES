/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:32:51 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/20 18:56:58 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->_vectorSequence = other._vectorSequence;
    this->_dequeSequence  = other._dequeSequence;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vectorSequence = other._vectorSequence;
        this->_dequeSequence  = other._dequeSequence;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printSequence(const std::string& state) const {
    std::cout << state << ": ";
    
    for (size_t i = 0; i < _vectorSequence.size(); ++i) {
        std::cout << _vectorSequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printSortTime(const std::string& containerName, size_t size, double time) const {
    std::cout << "Time to process a range of " << size 
              << " elements with " << containerName << " : " 
              << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

void PmergeMe::processSequences(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return ;
    }

    for (size_t i = 1; i < ac; ++i) {
        std::string arg = av[i];
        
        if (arg.empty()) {
            std::cerr << "Error" << std::endl;
            return ;
        }

        for (size_t j = 0; j < arg.length(); ++j) {
            if (!isdigit(arg[j]) && (j != 0 && arg[j] == '+')) {
                std::cerr << "Error" << std::endl;
                return ;
            }
        }
        
        char *endPtr;
        long value = std::strtol(arg.c_str(), &endPtr, 10);

        if (*endPtr != '\0' || value < 0 || value > INT_MAX) {
            std::cerr << "Error" << std::endl;
            return ;
        }

        _vectorSequence.push_back(static_cast<int>(value));
        _dequeSequence.push_back(static_cast<int>(value));
    }
    printSequence("Before");
    
    double timeVector = measureSortTime(_vectorSequence);
    double timeDeque  = measureSortTime(_dequeSequence);

    printSequence("After");

    printSortTime("std::vector", _vectorSequence.size(), timeVector);
    printSortTime("std::deque", _dequeSequence.size(), timeDeque);
}