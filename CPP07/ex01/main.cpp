/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 18:56:24 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 18:56:24 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

/* ========================================================================== */
/*                          AUXILIARY FUNCTIONS                               */
/* ========================================================================== */

template <typename T> void print(const T &elem)
{
	std::cout << elem << " ";
}

void	increment(int &n)
{
	n++;
}

void	duplicate(int &n)
{
	n *= 2;
}

void	toUpper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

/* ========================================================================== */
/*                         	      MAIN TESTS                                  */
/* ========================================================================== */

int	main(void)
{
	std::cout << "\n=== TEST 1: Array de int (no-const) ===" << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};
		size_t length = 5;

		std::cout << "Original: ";
		::iter(arr, length, print<int>);
		std::cout << std::endl;

		std::cout << "Incrementando elementos..." << std::endl;
		::iter(arr, length, increment);
		std::cout << "Después de increment: ";
		::iter(arr, length, print<int>);
		std::cout << std::endl;

		std::cout << "Duplicando elementos..." << std::endl;
		::iter(arr, length, duplicate);
		std::cout << "Después de duplicate: ";
		::iter(arr, length, print<int>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 2: Array de const int ===" << std::endl;
	{
		const int carr[] = {10, 20, 30, 40, 50};
		size_t length = 5;

		std::cout << "Const array: ";
		::iter(carr, length, print<int>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 3: Array de std::string ===" << std::endl;
	{
		std::string words[] = {"hello", "world", "from", "iter"};
		size_t length = 4;

		std::cout << "Original: ";
		::iter(words, length, print<std::string>);
		std::cout << std::endl;

		std::cout << "Convirtiendo a mayúsculas..." << std::endl;
		::iter(words, length, toUpper);
		std::cout << "Después de toUpper: ";
		::iter(words, length, print<std::string>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 4: Array de float ===" << std::endl;
	{
		float floats[] = {1.1f, 2.2f, 3.3f, 4.4f};
		size_t length = 4;

		std::cout << "Float array: ";
		::iter(floats, length, print<float>);
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 5: Array de char ===" << std::endl;
	{
		char chars[] = {'a', 'b', 'c', 'd', 'e'};
		size_t length = 5;

		std::cout << "Char array: ";
		::iter(chars, length, print<char>);
		std::cout << std::endl;
	}

	return (0);
}