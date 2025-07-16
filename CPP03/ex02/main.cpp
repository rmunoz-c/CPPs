/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 14:15:31 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-15 14:15:31 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n--- Creating ClapTrap ---" << std::endl;
	ClapTrap ct("C-18");
	ct.attack("Enemy1");
	ct.takeDamage(5);
	ct.beRepaired(3);
	
	std::cout << "\n--- Creating ScavTrap ---" << std::endl;
	ScavTrap st("C-16");
	st.attack("Enemy2");
	st.takeDamage(20);
	st.beRepaired(10);
	st.guardGate();

	std::cout << "\n--- Creating FragTrap ---" << std::endl;
	FragTrap ft("C-17");
	ft.attack("Enemy3");
	ft.takeDamage(20);
	ft.beRepaired(10);
	ft.highFivesGuys();

	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	FragTrap stCopy(ft);

	std::cout << "\n--- Testing assignment ---" << std::endl;
	FragTrap ftAssign;
	ftAssign = ft;

	std::cout << "\n--- End of scope ---" << std::endl;

	return (0);
}