/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 14:46:12 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-15 14:46:12 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been created (default)!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ScavTrap " << this->name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ScavTrap " << this->name << " has been assigned!" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target
			<< ", causing " << this->attackDamage << " ponts of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot enter Gate keeper mode because it has no hit points left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}
