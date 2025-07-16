/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 10:43:12 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-15 10:43:12 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;

	Fixed sum = b + c;
    Fixed diff = c - b;
    Fixed prod = b * c;
    Fixed quot = c / b;

    std::cout << "b + c = " << sum << std::endl;
    std::cout << "c - b = " << diff << std::endl;
    std::cout << "b * c = " << prod << std::endl;
    std::cout << "c / b = " << quot << std::endl;

    Fixed e;
    std::cout << "e is " << e << std::endl;
    std::cout << "++e is " << ++e << std::endl;
    std::cout << "e++ is " << e++ << std::endl;
    std::cout << "e is now " << e << std::endl;
    std::cout << "--e is " << --e << std::endl; 
    std::cout << "e-- is " << e-- << std::endl; 
    std::cout << "e is now " << e << std::endl;

	const Fixed &minVal = Fixed::min(b, c);
	const Fixed &maxVal = Fixed::max(b, c);
    std::cout << "min(b, c) = " << minVal << std::endl;
    std::cout << "max(b, c) = " << maxVal << std::endl;

    const Fixed f1(5.5f);
    const Fixed f2(2.2f);

    const Fixed &minConst = Fixed::min(f1, f2);
    const Fixed &maxConst = Fixed::max(f1, f2);
    std::cout << "min(f1, f2) = " << minConst << std::endl;
    std::cout << "max(f1, f2) = " << maxConst << std::endl;

    std::cout << std::boolalpha;
    std::cout << "b > c? " << (b > c) << std::endl;
    std::cout << "b < c? " << (b < c) << std::endl;
    std::cout << "b >= d? " << (b >= d) << std::endl;
    std::cout << "b <= d? " << (b <= d) << std::endl;
    std::cout << "b == d? " << (b == d) << std::endl;
    std::cout << "b != c? " << (b != c) << std::endl;

	return (0);
}