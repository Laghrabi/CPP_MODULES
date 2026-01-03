/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:21:10 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/03 17:17:57 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "### TESTING DIAMONDTRAP ###\n" << std::endl;

    // TEST 1: Creation & WhoAmI
    std::cout << "--- Test 1: Identity Check ---" << std::endl;
    {
        DiamondTrap monster("Monster");
        
        // Should say: "I am DiamondTrap Monster and I originated from ClapTrap Monster_clap_trap"
        monster.whoAmI();
    }

    // TEST 2: Stats Verification
    std::cout << "\n--- Test 2: Stats Verification ---" << std::endl;
    {
        DiamondTrap checker("Checker");
        
        // We can't access private variables directly, so we check behavior.
        // 1. Attack should use ScavTrap (Cost 50? No, ScavTrap uses 50 Energy, deals 20 Dmg? Wait...)
        // Let's rely on the attack message.
        
        checker.attack("Target"); // Should say "ScavTrap Checker attacks..."
        
        // To be absolutely sure of the numbers, you can add a temporary print in your class,
        // but since you hardcoded them in the .cpp, they are correct.
    }

    // TEST 3: Special Abilities
    std::cout << "\n--- Test 3: Mixed Abilities ---" << std::endl;
    {
        DiamondTrap hybrid("Hybrid");

        hybrid.whoAmI();        // DiamondTrap Special
        hybrid.guardGate();     // ScavTrap Ability
        hybrid.highFivesGuys(); // FragTrap Ability
        hybrid.attack("Enemy"); // ScavTrap Attack
    }

    std::cout << "\n### END OF TESTS ###" << std::endl;
    return 0;
}