/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:58:47 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/23 20:37:03 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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

bool isDoublePseudoLiteral(const std::string& input)
{
    std::string doublePseudo[] = {"nan", "inf", "+inf", "-inf"};

    for (int i = 0; i < 4; i++)
    {
        if (input == doublePseudo[i])
            return (true);
    }
    return (false);
}

bool isFloatPseudoLiteral(const std::string& input)
{
    std::string floatPseudo[] = {"nanf", "inff", "+inff", "-inff"};

    for (int i = 0; i < 4; i++)
    {
        if (input == floatPseudo[i])
            return (true);
    }
    return (false);
}

t_datatype  getDatatype(std::string& str)
{
    if (str.empty())
        return (NONE);
    if (isFloatPseudoLiteral(str))
        return (FLOAT);
    if (isDoublePseudoLiteral(str))
        return (DOUBLE);
    if (isChar(str))
        return (CHAR);
    if (isInt(str))
        return (INT);
    if (isFloat(str))
        return (FLOAT);
    if (isDouble(str))
        return (DOUBLE);
    return (NONE);
}
