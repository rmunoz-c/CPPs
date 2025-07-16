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
#include <iostream>

int main()
{
	std::cout << "\n--- Creating ClapTrap ---" << std::endl;
	ClapTrap ct("P-body");
	ct.attack("Enemy1");
	ct.takeDamage(5);
	ct.beRepaired(3);
	
	std::cout << "\n--- Creating ScavTrap ---" << std::endl;
	ScavTrap st("ATLAS");
	st.attack("Enemy2");
	st.takeDamage(20);
	st.beRepaired(10);
	st.guardGate();

	std::cout << "\n--- Testing copy constructor ---" << std::endl;
	ScavTrap stCopy(st);

	std::cout << "\n--- Testing assignment ---" << std::endl;
	ScavTrap stAssign;
	stAssign = st;

	std::cout << "\n--- End of scope ---" << std::endl;

	return (0);
}