/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:23:30 by claghrab          #+#    #+#             */
/*   Updated: 2026/03/23 19:05:24 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>

#define CHAR_MAX std::numeric_limits<char>::max()
#define CHAR_MIN std::numeric_limits<char>::min()

#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()

#define FLOAT_MAX std::numeric_limits<float>::max()
#define FLOAT_MIN std::numeric_limits<float>::min()

#define DOUBLE_MAX std::numeric_limits<double>::max()
#define DOUBLE_MIN std::numeric_limits<double>::min()

typedef enum e_datatype
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
} t_datatype;

t_datatype getDatatype(std::string &str);

// ScalarConverter Class
class   ScalarConverter {
        private:
            ScalarConverter();
            ScalarConverter(const ScalarConverter& other);
            ScalarConverter& operator=(const ScalarConverter& other);
        public:
            ~ScalarConverter();
            static void convert(std::string& input);
};

#endif