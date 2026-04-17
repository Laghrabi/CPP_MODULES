/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:28:48 by claghrab          #+#    #+#             */
/*   Updated: 2026/04/14 18:06:39 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"

// int main ()
// {
//     try {
//         std::vector<int> v;
//         v.push_back(1);
//         v.push_back(2);
//         v.push_back(3);
//         easyfind(v, 42);
//     }
//     catch (std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }
//     try {
//         std::vector<int> v;
//         v.push_back(1);
//         v.push_back(2);
//         v.push_back(3);
//         easyfind(v, 42);
//     }
//     catch (std::exception &e) {
//         std::cout << e.what() << std::endl;
//     }
// }

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::cout << "--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    try {
        std::cout << "Looking for 30... ";
        std::vector<int>::iterator it1 = easyfind(vec, 30);
        std::cout << "Success! Found: " << *it1 << std::endl;

        std::cout << "Looking for 99... ";
        std::vector<int>::iterator it2 = easyfind(vec, 99);
        std::cout << "Success! Found: " << *it2 << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "\n" << e.what() << std::endl;
    }

    std::cout << "\n";

    std::cout << "--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::cout << "Looking for 2... ";
        std::list<int>::iterator it3 = easyfind(lst, 2);
        std::cout << "Success! Found: " << *it3 << std::endl;
        std::cout << "Looking for 42... ";
        std::list<int>::iterator it4 = easyfind(lst, 42);
        std::cout << "Success! Found: " << *it4 << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "\n" << e.what() << std::endl;
    }

    return (0);
}
