/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:04:14 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/14 23:30:17 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void increment(int& n)
{
    n++;
}

void printInt(const int& n)
{
    std::cout << n << " ";
}

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

int main()
{
    
    std::cout << "--- Test 1: Modifying an integer array ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Before: ";
    ::iter(intArray, intLen, printInt);
    std::cout << std::endl;

    ::iter(intArray, intLen, increment);

    std::cout << "After:  ";
    ::iter(intArray, intLen, printInt);
    std::cout << std::endl << std::endl;


    std::cout << "--- Test 2: Reading a const integer array ---" << std::endl;
    const int constIntArray[] = {10, 20, 30};
    size_t constIntLen = sizeof(constIntArray) / sizeof(constIntArray[0]);
    
    std::cout << "Const Array: ";
    ::iter(constIntArray, constIntLen, printInt);
    std::cout << std::endl << std::endl;

    std::cout << "--- Test 3: String array with a template function ---" << std::endl;
    std::string stringArray[] = {"Hello", "42", "World"};
    size_t stringLen = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Strings: ";
    ::iter(stringArray, stringLen, printElement<std::string>); 
    std::cout << std::endl;

    return 0;
}
