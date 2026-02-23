/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:18:44 by claghrab          #+#    #+#             */
/*   Updated: 2026/02/22 23:52:55 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string& input)
{
    if(input.length() == 1 && isdigit(input[0]) == 0 && isprint(input[0]) != 0)
        return (true);
    else
        return (false);
}

bool isInt(const std::string& input)
{
    size_t  i = 0;
    size_t  len = input.length();

    if (len != 1 && (input[i] == '+' || input[i] == '-'))
        i++;
    while (i < len)
    {
        if (isdigit(input[i]) == 0)
            return (false);
        i++;
    }
    return (true);
}

bool isFloat(const std::string& input)
{
    int     dot = 0;
    int     f = 0;
    size_t  i = 0;
    size_t  len = input.length();

    if (len != 1 && (input[i] == '+' || input[i] == '-'))
        i++;
    while (i < len)
    {
        if (dot == 0 && input[i] == '.' && i != 0 && input[i + 1] != 'f')
            dot = 1;
        else if (f == 0 && i == (len - 1) && input[i] == 'f')
            f = 1;
        else if (isdigit(input[i]) == 0)
            return (false);
        i++;
    }
    if (dot == 0 || f == 0)
        return (false);
    return (true);
}

bool isDouble(const std::string& input)
{
    int     dot = 0;
    size_t  i = 0;
    size_t  len = input.length();

    if (len != 1 && (input[i] == '+' || input[i] == '-'))
        i++;
    while (i < len)
    {
        if (dot == 0 && input[i] == '.' && i != 0 && i + 1 != len)
            dot = 1;
        else if (isdigit(input[i]) == 0)
            return (false);
        i++;
    }
    if (dot == 0)
        return (false);
    return (true);
}

bool isPseudoLiteral(const std::string& input)
{
    int i = 0;
    std::string doublePseudo[] = {"nan", "inf", "+inf", "-inf"};
    std::string floatPseudo[] = {"nanf", "inff", "+inff", "-inff"};

    while (i < 4)
    {
        if (input == doublePseudo[i] || input == floatPseudo[i])
            return (true);
        i++;
    }
    return (false);
}
void ScalarConverter::convert(std::string& input)
{
    double  baseValue;
    char*   endPtr;

    if (isPseudoLiteral(input))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (input.find("nan") != std::string::npos)
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else
        {
            std::string sign = (input[0] == '-') ? "-" : "";
            std::cout << "float: " << sign << "inff" << std::endl;
            std::cout << "double: " << sign << "inf" << std::endl;
        }
        return ;
    }
    if (isChar(input))
        baseValue = static_cast<double>(input[0]);
    else if (isInt(input))
        baseValue = strtod(input.c_str(), &endPtr); 
    else if (isFloat(input))
        baseValue = static_cast<double>(strtof(input.c_str(), &endPtr));
    else if (isDouble(input))
        baseValue = strtod(input.c_str(), &endPtr);
    else
    {
        std::cout << "Error: Unknown type" << std::endl;
        return ;
    }
    std::cout << "char: ";
    if (baseValue < 0 || baseValue > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(baseValue)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(baseValue) << "'" << std::endl;
    std::cout << "int: ";
    if (baseValue > std::numeric_limits<int>::max() || baseValue < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(baseValue) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(baseValue) << "f" << std::endl;
    std::cout << "double: " << baseValue << std::endl;
}
