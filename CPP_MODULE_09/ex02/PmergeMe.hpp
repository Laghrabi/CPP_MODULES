/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:32:48 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/21 00:34:52 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>
#include <string>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <iomanip>

#define INT_MAX 2147483647

class PmergeMe {
    private:
        std::vector<int> _vectorSequence;
        std::deque<int>  _dequeSequence;

        size_t getJacobsthal(size_t n) const;
        template <typename Container>
        void mergeInsertSort(Container& sequence);
        template <typename Container>
        double measureSortTime(Container& sequence);
        
        void printSequence(const std::string& state) const;
        void printSortTime(const std::string& containerName, size_t size, double time) const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void processSequences(int argc, char** argv);
};

template <typename Container>
double PmergeMe::measureSortTime(Container& sequence) {
    clock_t start = clock();
    mergeInsertSort(sequence); 
    clock_t end = clock();

    return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0);
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& sequence) {
    if (sequence.size() < 2)
        return ;
    
    bool hasStraggler = (sequence.size() % 2 != 0);
    int straggler = -1;
    if (hasStraggler)
        straggler = sequence.back();
    
    std::vector<std::pair<int, int> > pairs;
    Container winners;
    
    for (size_t i = 0; i < (sequence.size() / 2); ++i) {
        int a = sequence[i * 2];
        int b = sequence[i * 2 + 1];

        if (a > b) {
            pairs.push_back(std::make_pair(a, b));
            winners.push_back(a);
        } else {
            pairs.push_back(std::make_pair(b, a));
            winners.push_back(b);
        }
    }

    mergeInsertSort(winners);

    Container pending;
    for (size_t i = 0; i < winners.size(); ++i) {
        
    }
}

#endif