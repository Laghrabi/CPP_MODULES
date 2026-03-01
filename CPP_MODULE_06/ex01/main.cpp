/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:52:26 by claghrab          #+#    #+#             */
/*   Updated: 2026/02/24 17:30:21 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.id = 42;
    myData.name = "John Doe";

    Data* originalPtr = &myData;
    
    std::cout << "--- Before Serialization ---" << std::endl;
    std::cout << "Original Pointer Address: " << originalPtr << std::endl;
    std::cout << "Data ID: " << originalPtr->id << " | Name: " << originalPtr->name << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);
    
    std::cout << "\n--- Serialization Result ---" << std::endl;
    std::cout << "Raw integer value: " << raw << " (Hex: 0x" << std::hex << raw << std::dec << ")" << std::endl;

    Data* finalPtr = Serializer::deserialize(raw);

    std::cout << "\n--- After Deserialization ---" << std::endl;
    std::cout << "Final Pointer Address:    " << finalPtr << std::endl;
    std::cout << "Data ID: " << finalPtr->id << " | Name: " << finalPtr->name << std::endl;

    std::cout << "\n--- Verification ---" << std::endl;
    if (finalPtr == originalPtr) {
        std::cout << "SUCCESS: The pointers match!" << std::endl;
    } else {
        std::cout << "FAILURE: The pointers are different!" << std::endl;
    }

    return 0;
}
