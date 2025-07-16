/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-11 13:59:33 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-11 13:59:33 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	std::cout << "Creating zombie on the heap:" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	std::cout << "Deleting heapZombie..." << std::endl;
	delete heapZombie;

	std::cout << std::endl << "Creating zombie on the stack:" << std::endl;
	randomChump("StackZombie");

	return (0);
}