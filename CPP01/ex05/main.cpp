/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 14:31:16 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 14:31:16 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::cout << "\033[35m" << "Testing DEBUG level:\n" << "\033[0m";
	harl.complain("DEBUG");
	std::cout << "\033[35m" << "\nTesting INFO level:\n" << "\033[0m";
	harl.complain("INFO");
	std::cout << "\033[35m" << "\nTesting WARNIG level:\n" << "\033[0m";
	harl.complain("WARNING");
	std::cout << "\033[35m" << "\nTesting ERROR level:\n" << "\033[0m";
	harl.complain("ERROR");
	std::cout << "\033[35m" << "\nTesting UNKNOWN level:\n" << "\033[0m";
	harl.complain("UNKNOWN");
	return (0);
}
