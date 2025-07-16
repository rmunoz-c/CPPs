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
#include <iostream>

int main()
{
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");

	robot1.attack("C3PO");
	robot2.takeDamage(5);
	robot2.beRepaired(3);

	robot2.attack("R2D2");
	robot1.takeDamage(8);
	robot1.beRepaired(4);

	robot1.attack("C3PO");
	robot2.takeDamage(10);

	return (0);
}