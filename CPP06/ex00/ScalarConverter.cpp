/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-09 17:43:29 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-02-09 17:43:29 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static bool isCharLiteral(const std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isSpecialLiteral(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" ||
			literal == "inf" || literal == "inff" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff");
}

static bool isFloatingLiteral(const std::string &literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return (false);
	if (literal.find('.') == std::string::npos)
		return (false);
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	if (start < literal.length() && literal[start] == '.')
		return (false);
	return (true);
	
}

static bool isDoubleLiteral(const std::string &literal)
{
	if (literal.find('.') == std::string::npos)
		return (false);
	if (literal[literal.length() - 1] == 'f')
		return (false);
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	if (start < literal.length() && literal[start] == '.')
		return (false);
	return (true);
}

static bool isIntLiteral(const std::string &literal)
{
	size_t i = 0;

	if (literal[0] == '+' || literal[0] == '-')
		i = 1;
	if (i >= literal.length())
		return (false);
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

static void printChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (value < 32 || value == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	float f = static_cast<float>(value);

	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	double value = 0.0;

	if (isCharLiteral(literal))
	{
		value = static_cast<double>(literal[1]);
	}
	else if (isSpecialLiteral(literal))
	{
		if (literal == "nan" || literal == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "inf" || literal == "inff" ||
				 literal == "+inf" || literal == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (literal == "-inf" || literal == "-inff")
			value = -std::numeric_limits<double>::infinity();
	}
	else if (isFloatingLiteral(literal))
	{
		std::string str = literal.substr(0, literal.length() - 1);
		value = std::atof(str.c_str());
	}
	else if (isDoubleLiteral(literal))
	{
		value = std::atof(literal.c_str());
	}
	else if (isIntLiteral(literal))
	{
		value = std::atof(literal.c_str());
	}
	else
	{
		std::cout << "Error: Invalid literal" << std::endl;
		return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

