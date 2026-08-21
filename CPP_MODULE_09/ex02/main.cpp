/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 14:32:56 by claghrab          #+#    #+#             */
/*   Updated: 2026/08/21 16:19:43 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return(1);
    }

    try {
        PmergeMe sorter;
        sorter.processSequences(argc, argv);
        
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    return (0);
}