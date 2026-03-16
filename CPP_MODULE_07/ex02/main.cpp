/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:50:16 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/15 23:50:38 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() 
{
    std::cout << "--- Empty Array Test ---" << std::endl;
    Array<int> empty;
    std::cout << "Size of empty array: " << empty.size() << std::endl;

    std::cout << "\n--- Parameterized Constructor Test ---" << std::endl;
    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); i++) {
        arr1[i] = i * 10;
        std::cout << "arr1[" << i << "] = " << arr1[i] << std::endl;
    }

    std::cout << "\n--- Copy Constructor (Deep Copy) Test ---" << std::endl;
    Array<int> arr2(arr1);
    arr2[0] = 999;
    std::cout << "arr1[0] : " << arr1[0] << " (Original unchanged)" << std::endl;
    std::cout << "arr2[0] : " << arr2[0] << " (Copy modified)" << std::endl;

    std::cout << "\n--- Assignment Operator (Deep Copy) Test ---" << std::endl;
    Array<int> arr3;
    arr3 = arr1;
    arr3[1] = 888;
    std::cout << "arr1[1] : " << arr1[1] << " (Original unchanged)" << std::endl;
    std::cout << "arr3[1] : " << arr3[1] << " (Copy modified)" << std::endl;

    std::cout << "\n--- Out of Bounds Exception Test ---" << std::endl;
    try {
        std::cout << "Attempting to access arr1[10]..." << std::endl;
        std::cout << arr1[10] << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- String Array Test ---" << std::endl;
    Array<std::string> strArr(2);
    strArr[0] = "Hello";
    strArr[1] = "42";
    std::cout << strArr[0] << " " << strArr[1] << std::endl;

    return 0;
}