/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:54:46 by claghrab          #+#    #+#             */
/*   Updated: 2025/12/29 16:23:45 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include "Fixed.hpp"

// Colors for readable output
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

void print_header(std::string title) {
    std::cout << "\n" << CYAN << "=== " << title << " ===" << RESET << std::endl;
}

void test_bool(bool result, std::string testName) {
    if (result)
        std::cout << GREEN << "[OK] " << RESET << testName << std::endl;
    else
        std::cout << RED << "[FAIL] " << RESET << testName << std::endl;
}

int main( void ) {

    // ---------------------------------------------------------
    // 1. THE OFFICIAL SUBJECT TEST (Must pass exactly)
    // ---------------------------------------------------------
    print_header("OFFICIAL SUBJECT TEST");
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << "a: " << a << std::endl;
        std::cout << "++a: " << ++a << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "a++: " << a++ << std::endl;
        std::cout << "a: " << a << std::endl;

        std::cout << "b: " << b << std::endl;

        std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;
    }

    // ---------------------------------------------------------
    // 2. CONSTRUCTORS & BASIC CONVERSION
    // ---------------------------------------------------------
    print_header("CONSTRUCTORS & VALUES");
    Fixed intVal(42);
    Fixed floatVal(42.42f);
    
    std::cout << "Int(42) as float: " << intVal.toFloat() << std::endl;
    std::cout << "Float(42.42) as float: " << floatVal.toFloat() << std::endl;

    // ---------------------------------------------------------
    // 3. ARITHMETIC OPERATORS (+, -, *, /)
    // ---------------------------------------------------------
    print_header("ARITHMETIC OPERATORS");
    Fixed x(10);
    Fixed y(2.5f);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    
    // Addition
    Fixed sum = x + y;
    std::cout << "x + y = " << sum << " (Expected: 12.5)" << std::endl;
    test_bool(sum.toFloat() == 12.5f, "Addition Check");

    // Subtraction
    Fixed diff = x - y;
    std::cout << "x - y = " << diff << " (Expected: 7.5)" << std::endl;
    test_bool(diff.toFloat() == 7.5f, "Subtraction Check");

    // Multiplication (Crucial: Checks if you divide by 256)
    Fixed mult = x * y;
    std::cout << "x * y = " << mult << " (Expected: 25)" << std::endl;
    test_bool(mult.toInt() == 25, "Multiplication Check");

    // Division (Crucial: Checks if you multiply by 256 first)
    Fixed div = x / y;
    std::cout << "x / y = " << div << " (Expected: 4)" << std::endl;
    test_bool(div.toInt() == 4, "Division Check");

    // ---------------------------------------------------------
    // 4. COMPARISON OPERATORS (>, <, >=, <=, ==, !=)
    // ---------------------------------------------------------
    print_header("COMPARISON OPERATORS");
    Fixed val1(10);
    Fixed val2(20);
    Fixed val3(10);

    test_bool(val2 > val1,  "20 > 10");
    test_bool(val1 < val2,  "10 < 20");
    test_bool(val1 >= val3, "10 >= 10");
    test_bool(val1 <= val3, "10 <= 10");
    test_bool(val1 == val3, "10 == 10");
    test_bool(val1 != val2, "10 != 20");

    // ---------------------------------------------------------
    // 5. INCREMENT / DECREMENT (Pre vs Post)
    // ---------------------------------------------------------
    print_header("INCREMENT / DECREMENT");
    Fixed i(1);

    std::cout << "Start: " << i << std::endl;
    std::cout << "Pre-inc (++i): " << ++i << " (Expected: 1.0039...)" << std::endl;
    std::cout << "After Pre-inc: " << i << std::endl;

    std::cout << "Post-inc (i++): " << i++ << " (Expected: 1.0039...)" << std::endl;
    std::cout << "After Post-inc: " << i << " (Expected: 1.0078...)" << std::endl;

    // ---------------------------------------------------------
    // 6. MIN / MAX FUNCTIONS
    // ---------------------------------------------------------
    print_header("MIN / MAX");
    Fixed small(5);
    Fixed big(10);
    const Fixed cSmall(2);
    const Fixed cBig(4);

    std::cout << "min(5, 10): " << Fixed::min(small, big) << std::endl;
    std::cout << "max(5, 10): " << Fixed::max(small, big) << std::endl;
    
    // Testing const versions
    std::cout << "min(const 2, const 4): " << Fixed::min(cSmall, cBig) << std::endl;
    std::cout << "max(const 2, const 4): " << Fixed::max(cSmall, cBig) << std::endl;

    return 0;
}