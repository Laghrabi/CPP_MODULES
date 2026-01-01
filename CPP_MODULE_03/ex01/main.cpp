/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:21:10 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/31 16:20:11 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{

    // TEST 1: Construction & Special Ability
    std::cout << "--- Test 1: Construction and Guard Mode ---" << std::endl;
    {
        ScavTrap serena("Serena");

        // Check if stats are correct (implicitly tested by survival)
        serena.attack("Target Dummy"); // Should print ScavTrap attack message
        serena.guardGate();            // Should print Gate keeper mode message
    } 
    // Destructor called here: Expect ScavTrap dtor -> ClapTrap dtor

    // TEST 2: Damage & Repair Loop (Testing inherited functions)
    std::cout << "\n--- Test 2: Damage & Repair ---" << std::endl;
    {
        ScavTrap robot("TankBot");

        // ScavTrap has 100 HP. Let's hit it hard.
        robot.takeDamage(50); // Should drop to 50 HP
        robot.beRepaired(20); // Should recover to 70 HP (Cost 1 Energy)
        robot.takeDamage(80); // Should drop to 0 HP (Death)
        
        // Try to act while dead
        robot.attack("Ghost");
        robot.guardGate(); // Technically this doesn't use energy/hp in your code, but good to test
    }

    // TEST 3: Copy Constructor & Assignment
    std::cout << "\n--- Test 3: Copy & Assignment ---" << std::endl;
    {
        ScavTrap original("Original");
        original.takeDamage(50); // HP is now 50

        ScavTrap copy(original); // Copy Constructor
        ScavTrap assigned("Temp"); 
        assigned = original;     // Assignment Operator

        // Both 'copy' and 'assigned' should have 50 HP now.
        std::cout << "Testing copied object (Should have 50 HP):" << std::endl;
        copy.attack("CloneTarget"); 
    }
    
    return 0;
}