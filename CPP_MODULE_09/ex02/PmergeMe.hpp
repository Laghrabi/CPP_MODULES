/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:32:48 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/21 16:23:42 by claghrab         ###   ########.fr       */
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
#include <cstdlib>

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
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (winners[i] == pairs[j].first) {
                pending.push_back(pairs[j].second);
                pairs[j].first = -1;
                break ;
            }
        }
    }

    if (hasStraggler)
        pending.push_back(straggler);
    
    sequence = winners;
    if (!sequence.empty())
        sequence.insert(sequence.begin(), pending[0]);

    size_t indexCount = 1;
    size_t jacobIndex = 3;

    while (indexCount < pending.size()) {
        size_t jacobVal = getJacobsthal(jacobIndex);
        size_t chunkEnd = std::min(jacobVal, pending.size());

        for (size_t i = chunkEnd; i > indexCount; --i) {
            int elementToInsert = pending[i - 1];
            typename Container::iterator insertPos = std::lower_bound(sequence.begin(), sequence.end(), elementToInsert);
            sequence.insert(insertPos, elementToInsert);
        }

        indexCount = chunkEnd;
        jacobIndex++;
    }
}

#endif