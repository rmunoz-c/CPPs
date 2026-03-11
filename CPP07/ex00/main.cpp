/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 18:41:31 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 18:41:31 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "\n=== Subject's main ===" << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}

	std::cout << "\n=== Additional tests ===" << std::endl;
	{
		std::cout << "\nTest with equal values:" << std::endl;
		int x = 5;
		int y = 5;
		std::cout << "x = " << x << ", y = " << y << std::endl;
		std::cout << "min( x, y ) = " << ::min(x, y) << " (should return y)" << std::endl;
		std::cout << "max( x, y ) = " << ::max(x, y) << " (should return y)" << std::endl;

		std::cout << "\nTest with floats:" << std::endl;
		float f1 = 3.14f;
		float f2 = 2.71f;
		std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
		::swap(f1, f2);
		std::cout << "After swap:  f1 = " << f1 << ", f2 = " << f2 << std::endl;
		std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
		std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;

		std::cout << "\nTest with negative numbers:" << std::endl;
		int neg1 = -10;
		int neg2 = -5;
		std::cout << "min( " << neg1 << ", " << neg2 << " ) = " << ::min(neg1, neg2) << std::endl;
		std::cout << "max( " << neg1 << ", " << neg2 << " ) = " << ::max(neg1, neg2) << std::endl;
	}

	return (0);
}