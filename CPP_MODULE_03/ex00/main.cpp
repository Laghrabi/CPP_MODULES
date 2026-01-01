/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:21:10 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/31 14:21:13 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    // TEST 1: The "Happy Path" (Attack, Damage, Repair)
    std::cout << "\n--- TEST 1: Standard Lifecycle ---" << std::endl;
    {
        ClapTrap robot("CL4P-TP");

        // 1. Attack (Costs 1 Energy)
        robot.attack("Handsome Jack");
        
        // 2. Take Damage (No Energy Cost)
        robot.takeDamage(5); // HP goes from 10 -> 5

        // 3. Repair (Costs 1 Energy)
        robot.beRepaired(3); // HP goes from 5 -> 8
        
        // 4. Take Fatal Damage
        robot.takeDamage(10); // HP goes from 8 -> 0
    } // Destructor called here

    // TEST 2: Energy Depletion
    std::cout << "\n--- TEST 2: Energy Depletion ---" << std::endl;
    {
        ClapTrap spammer("SpamBot");

        // Loop to drain all 10 Energy Points
        for (int i = 0; i < 10; i++)
        {
            spammer.attack("Target Dummy");
        }

        // Try one more action with 0 Energy
        std::cout << ">> Attempting action with 0 Energy:" << std::endl;
        spammer.attack("The Void");
        spammer.beRepaired(5);
    } // Destructor called here

    // TEST 3: Action While Dead
    std::cout << "\n--- TEST 3: Zombie Logic (Actions at 0 HP) ---" << std::endl;
    {
        ClapTrap zombie("Kenny");

        // Kill it immediately
        zombie.takeDamage(100); 

        // Try to revive (Should fail due to 0 HP)
        std::cout << ">> Attempting repair while dead:" << std::endl;
        zombie.beRepaired(10);

        // Try to attack (Should fail due to 0 HP)
        std::cout << ">> Attempting attack while dead:" << std::endl;
        zombie.attack("The Air");
    } // Destructor called here

    return (0);
}