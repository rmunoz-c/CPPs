/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-15 13:47:06 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-15 13:47:06 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has been created (default)!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap " << this->name << " has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " has been assigned!" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack because it has no hit points left!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack because it has no energy points left!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target
			<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already destroyed and can't take more damage!" << std::endl;
		return;
	}
	if (amount >= this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes "  << amount 
			<< " points of damage! Remaining hit points: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot repair because it has no hit points left!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot repair because it has no energy points left!" << std::endl;
		return;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
}
