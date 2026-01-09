/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:31:36 by claghrab          #+#    #+#             */
/*   Updated: 2026/01/08 21:54:06 by claghrab         ###   ########.fr       */
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
    std::cout << "\n=== 2. DEEP COPY & MEMORY TEST ===" << std::endl;
    
    // 1. Setup the Factory
    // Create the source and teach it the "templates" for Ice and Cure.
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // 2. Create the Original Character
    Character* bob = new Character("Bob");
    
    AMateria* originalIce = src->createMateria("ice");
    bob->equip(originalIce);
    
    // 4. Test Copy Constructor (The Core Test)
    Character* bobCopy = new Character(*bob);

    // 5. Verify Both Have Items
    std::cout << "Original Bob uses item 0:" << std::endl;
    bob->use(0, *bobCopy); // Should print "shoots an ice bolt"

    std::cout << "Copy Bob uses item 0:" << std::endl;
    bobCopy->use(0, *bob); // Should print "shoots an ice bolt"

    // 6. Modify the Original (Test Independence)
    std::cout << "Unequipping slot 0 from Original Bob..." << std::endl;
    bob->unequip(0); 
    
    // 7. Manual Cleanup (Zero Leaks)
    delete originalIce;

    // 8. Verify Original is Empty
    std::cout << "Original Bob tries to use item 0 (Should do nothing):" << std::endl;
    bob->use(0, *bobCopy); 

    // 9. PROOF OF DEEP COPY
    std::cout << "Copy Bob uses item 0 (Should still work - Deep Copy):" << std::endl;
    bobCopy->use(0, *bob); 

    // 10. Clean Up
    delete bob;
    delete bobCopy;
    delete src;
}

int main() {
    testSubjectMain();
    testDeepCopy();
    return 0;
}