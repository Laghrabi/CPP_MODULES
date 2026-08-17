/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:22:11 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/09 15:26:15 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // ========================================================
    // TEST 1: The Abstract Class Check
    // ========================================================
    std::cout << "--- 1. Abstract Class Test ---" << std::endl;
    
    // Uncommenting the lines below MUST cause a compilation error.
    // If it compiles, you failed the exercise!
    
    // Animal test; 
    // Animal* test2 = new Animal();

    std::cout << "Success: Animal cannot be instantiated directly." << std::endl;

    return 0;
}