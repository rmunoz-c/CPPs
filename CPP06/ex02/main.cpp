/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 18:17:53 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 18:17:53 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void)
{
	srand(time(NULL));

	std::cout << "\n=== TEST 1: Generate random objects ===" << std::endl;
	{
		std::cout << "\nGenerating 5 random objects:\n" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			Base *ptr = generate();
			std::cout << "Object " << i + 1 << ": ";
			identify(ptr);
			delete ptr;
		}
	}

	std::cout << "\n=== TEST 2: Identify with pointer ===" << std::endl;
	{
		std::cout << "\nCreating A, B, C explicitly:\n" << std::endl;

		Base *a = new A();
		std::cout << "Type A identified as: ";
		identify(a);
		delete a;

		Base *b = new B();
		std::cout << "Type B identified as: ";
		identify(b);
		delete b;

		Base *c = new C();
		std::cout << "Type C identified as: ";
		identify(c);
		delete c;
	}

	std::cout << "\n=== TEST 3: Identify with reference ===" << std::endl;
	{
		std::cout << "\nCreating A, B, C explicitly:\n" << std::endl;

		Base *a = new A();
		std::cout << "Type A identified as: ";
		identify(*a);
		delete a;

		Base *b = new B();
		std::cout << "Type B identified as: ";
		identify(*b);
		delete b;

		Base *c = new C();
		std::cout << "Type C identified as: ";
		identify(*c);
		delete c;
	}

	std::cout << "\n=== TEST 4: Both methods give same result ===" << std::endl;
	{
		std::cout << "\nComparing pointer vs reference identification:\n" << std::endl;

		for (int i = 0; i < 3; i++)
		{
			Base *ptr = generate();
			std::cout << "Object " << i + 1 << ":" << std::endl;
			std::cout << "  Via pointer:   ";
			identify(ptr);
			std::cout << "  Via reference: ";
			identify(*ptr);
			delete ptr;
			std::cout << std::endl;
		}
	}

	std::cout << "=== All tests completed! ===" << std::endl;

	return (0);
}