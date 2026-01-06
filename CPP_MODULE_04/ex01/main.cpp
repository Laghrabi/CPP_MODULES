/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 21:22:11 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/06 21:25:51 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "--- 1. Testing Deep Copy ---" << std::endl;
    Dog* dogA = new Dog();
    
    // Set an idea in Dog A
    dogA->setIdea(0, "I want a bone");
    std::cout << "Dog A Idea: " << dogA->getIdea(0) << std::endl;

    // Create Dog B as a copy of Dog A
    Dog* dogB = new Dog(*dogA);
    std::cout << "Dog B Idea (Should be 'I want a bone'): " << dogB->getIdea(0) << std::endl;

    // Modify Dog A
    dogA->setIdea(0, "I want to sleep");
    std::cout << "Dog A modified: " << dogA->getIdea(0) << std::endl;
    std::cout << "Dog B Check (Should still be 'I want a bone'): " << dogB->getIdea(0) << std::endl;

    // Verify Memory Addresses are different
    if (&dogA->getIdea(0) != &dogB->getIdea(0))
        std::cout << "SUCCESS: Ideas are in different memory locations!" << std::endl;
    else
        std::cout << "FAILURE: Shallow Copy detected!" << std::endl;

    delete dogA;
    delete dogB;

    std::cout << "\n--- 2. Testing Array of Animals ---" << std::endl;
    Animal* animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 4; i++)
        delete animals[i]; // Should trigger Brain destructors

    return (0);
}