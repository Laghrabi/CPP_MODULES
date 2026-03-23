/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:18:44 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/23 20:59:20 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

template <typename T>
void    printOutput(T val)
{
    std::cout << "char: ";
    if (std::isnan(static_cast<double>(val)) || val < CHAR_MIN || val > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<char>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(static_cast<double>(val)) || val < INT_MIN || val > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void ScalarConverter::convert(std::string& input)
{
    t_datatype  type = getDatatype(input);
    char* endPtr;

    switch (type)
    {
        case CHAR:
        {
            char c = input[0];
            printOutput(c);
            break;
        }
        case INT:
        {
            long l = strtol(input.c_str(), &endPtr, 10);
            if (l < INT_MIN || l > INT_MAX)
                printOutput(static_cast<double>(l));
            else
                printOutput(static_cast<int>(l));
            break;
        }
        case FLOAT:
        {
            float f = strtof(input.c_str(), &endPtr);
            printOutput(f);
            break;
        }
        case DOUBLE:
        {
            double d = strtod(input.c_str(), &endPtr);
            printOutput(d);
            break;
        }
        case NONE:
            std::cout << "Error: Unknown type" << std::endl;
            break;
    }
}
