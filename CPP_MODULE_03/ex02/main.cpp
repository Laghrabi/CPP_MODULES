/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:21:10 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/03 15:34:45 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{

    // TEST 1: Construction & Special Ability
    std::cout << "--- Test 1: Construction and High Fives ---" << std::endl;
    {
        FragTrap steve("Steve");

        // Test the special ability
        steve.highFivesGuys();
        
        // Test inherited attack (Should deal 30 damage)
        steve.attack("Alien"); 
    } 
    // Destructor Order: FragTrap first, then ClapTrap

    // TEST 2: Status & Durability
    std::cout << "\n--- Test 2: Durability Test (100 HP) ---" << std::endl;
    {
        FragTrap tank("Tanky");

        // FragTrap starts with 100 HP. Let's verify it can take a beating.
        tank.takeDamage(50); 
        std::cout << ">> Tanky should have 50 HP left." << std::endl;
        
        tank.beRepaired(20); 
        std::cout << ">> Tanky should have 70 HP left." << std::endl;
        
        tank.highFivesGuys();
    }

    // TEST 3: Energy Limits
    std::cout << "\n--- Test 3: Activity Check ---" << std::endl;
    {
        FragTrap active("ActiveBot");

        // Just proving it functions like a ClapTrap
        active.attack("Target A");
        active.attack("Target B");
        active.highFivesGuys();
    }

    return (0);
}