/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:31:36 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/09 15:59:19 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void testSubjectMain() {
    std::cout << "\n=== 1. SUBJECT MAIN TEST ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

void testDeepCopy() {
    std::cout << "=== 1. Setup Source (Magic Shop) ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== 2. Create Character (Me) ===" << std::endl;
    ICharacter* me = new Character("me");

    std::cout << "\n=== 3. Equip Items ===" << std::endl;
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== 4. Use Items on Bob ===" << std::endl;
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob); // Should print: * shoots an ice bolt at bob *
    me->use(1, *bob); // Should print: * heals bob's wounds *

    std::cout << "\n=== 5. Cleanup ===" << std::endl;
    delete bob;
    delete me;
    delete src;
}

int main() {
    //testSubjectMain();
    testDeepCopy();
    return 0;
}