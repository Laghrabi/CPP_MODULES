/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:15:49 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/01 17:25:11 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    std::srand(std::time(NULL));

    std::cout << "--- Testing Random Object Generation ---" << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;
        
        Base* randomObj = generate();

        std::cout << "Identify via pointer:   ";
        identify(randomObj);

        std::cout << "Identify via reference: ";
        identify(*randomObj);

        delete randomObj;
    }

    return 0;
}