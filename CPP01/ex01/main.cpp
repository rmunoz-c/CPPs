/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-11 14:41:31 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-11 14:41:31 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int N;

	N = 5;
	std::string name = "HordeZombie";
	std::cout << "Creating a horde of " << N << " zombies called '" << name << "'..." << std::endl;
	Zombie* horde = zombieHorde(N, name);
	if (horde == NULL)
	{
		std::cout << "Could not create horde." << std:: endl;
		return (1);
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
