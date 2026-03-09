/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-09 18:25:31 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-02-09 18:25:31 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

int main(void)
{
    std::cout << "\n=== TEST 1: Char literals ===" << std::endl;
    {
        std::cout << "\n→ Input: 'a'" << std::endl;
        ScalarConverter::convert("'a'");
        
        std::cout << "\n→ Input: 'z'" << std::endl;
        ScalarConverter::convert("'z'");
        
        std::cout << "\n→ Input: '*'" << std::endl;
        ScalarConverter::convert("'*'");
    }

    std::cout << "\n=== TEST 2: Int literals ===" << std::endl;
    {
        std::cout << "\n→ Input: 0" << std::endl;
        ScalarConverter::convert("0");
        
        std::cout << "\n→ Input: 42" << std::endl;
        ScalarConverter::convert("42");
        
        std::cout << "\n→ Input: -42" << std::endl;
        ScalarConverter::convert("-42");
        
        std::cout << "\n→ Input: 2147483647 (INT_MAX)" << std::endl;
        ScalarConverter::convert("2147483647");
    }

    std::cout << "\n=== TEST 3: Float literals ===" << std::endl;
    {
        std::cout << "\n→ Input: 0.0f" << std::endl;
        ScalarConverter::convert("0.0f");
        
        std::cout << "\n→ Input: 42.0f" << std::endl;
        ScalarConverter::convert("42.0f");
        
        std::cout << "\n→ Input: -4.2f" << std::endl;
        ScalarConverter::convert("-4.2f");
        
        std::cout << "\n→ Input: 4.2f" << std::endl;
        ScalarConverter::convert("4.2f");
    }

    std::cout << "\n=== TEST 4: Double literals ===" << std::endl;
    {
        std::cout << "\n→ Input: 0.0" << std::endl;
        ScalarConverter::convert("0.0");
        
        std::cout << "\n→ Input: 42.0" << std::endl;
        ScalarConverter::convert("42.0");
        
        std::cout << "\n→ Input: -4.2" << std::endl;
        ScalarConverter::convert("-4.2");
        
        std::cout << "\n→ Input: 4.2" << std::endl;
        ScalarConverter::convert("4.2");
    }

    std::cout << "\n=== TEST 5: Special literals (pseudo-literals) ===" << std::endl;
    {
        std::cout << "\n→ Input: nan" << std::endl;
        ScalarConverter::convert("nan");
        
        std::cout << "\n→ Input: nanf" << std::endl;
        ScalarConverter::convert("nanf");
        
        std::cout << "\n→ Input: inf" << std::endl;
        ScalarConverter::convert("inf");
        
        std::cout << "\n→ Input: inff" << std::endl;
        ScalarConverter::convert("inff");
        
        std::cout << "\n→ Input: +inf" << std::endl;
        ScalarConverter::convert("+inf");
        
        std::cout << "\n→ Input: -inf" << std::endl;
        ScalarConverter::convert("-inf");
        
        std::cout << "\n→ Input: -inff" << std::endl;
        ScalarConverter::convert("-inff");
    }

    std::cout << "\n=== TEST 6: Non-displayable chars ===" << std::endl;
    {
        std::cout << "\n→ Input: 0 (ASCII 0 - NULL)" << std::endl;
        ScalarConverter::convert("0");
        
        std::cout << "\n→ Input: 31 (ASCII 31 - Unit Separator)" << std::endl;
        ScalarConverter::convert("31");
        
        std::cout << "\n→ Input: 127 (ASCII 127 - DEL)" << std::endl;
        ScalarConverter::convert("127");
    }

    std::cout << "\n=== TEST 7: Displayable chars ===" << std::endl;
    {
        std::cout << "\n→ Input: 32 (ASCII 32 - Space)" << std::endl;
        ScalarConverter::convert("32");
        
        std::cout << "\n→ Input: 65 (ASCII 65 - 'A')" << std::endl;
        ScalarConverter::convert("65");
        
        std::cout << "\n→ Input: 126 (ASCII 126 - '~')" << std::endl;
        ScalarConverter::convert("126");
    }

    std::cout << "\n=== TEST 8: Out of range ===" << std::endl;
    {
        std::cout << "\n→ Input: -200 (out of ASCII range)" << std::endl;
        ScalarConverter::convert("-200");
        
        std::cout << "\n→ Input: 300 (out of ASCII range)" << std::endl;
        ScalarConverter::convert("300");
        
        std::cout << "\n→ Input: 2147483648 (INT_MAX + 1)" << std::endl;
        ScalarConverter::convert("2147483648");
    }

    std::cout << "\n=== TEST 9: Edge cases ===" << std::endl;
    {
        std::cout << "\n→ Input: +42" << std::endl;
        ScalarConverter::convert("+42");
        
        std::cout << "\n→ Input: +42.5f" << std::endl;
        ScalarConverter::convert("+42.5f");
        
        std::cout << "\n→ Input: -0.0f" << std::endl;
        ScalarConverter::convert("-0.0f");
    }

    std::cout << "\n=== TEST 10: Invalid inputs ===" << std::endl;
    {
        std::cout << "\n→ Input: abc (invalid)" << std::endl;
        ScalarConverter::convert("abc");
        
        std::cout << "\n→ Input: 42f (missing decimal point)" << std::endl;
        ScalarConverter::convert("42f");
        
        std::cout << "\n→ Input: .5 (missing leading digit)" << std::endl;
        ScalarConverter::convert(".5");
        
        std::cout << "\n→ Input: '' (empty char)" << std::endl;
        ScalarConverter::convert("''");
        
        std::cout << "\n→ Input: 'ab' (multiple chars)" << std::endl;
        ScalarConverter::convert("'ab'");
    }

    std::cout << "\n=== TEST 11: Subject examples ===" << std::endl;
    {
        std::cout << "\n→ Input: 0 (subject example)" << std::endl;
        ScalarConverter::convert("0");
        
        std::cout << "\n→ Input: nan (subject example)" << std::endl;
        ScalarConverter::convert("nan");
        
        std::cout << "\n→ Input: 42.0f (subject example)" << std::endl;
        ScalarConverter::convert("42.0f");
    }

    std::cout << "\n=== All tests completed! ===" << std::endl;

    return (0);
}