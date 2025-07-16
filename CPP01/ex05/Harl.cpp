/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 14:17:54 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 14:17:54 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug(void)
{
	std::cout << "\033[36m" "[ DEBUG ]" << "\033[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[32m" "[ INFO ]" << "\033[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enought bacon in my burger! IF you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[33m" "[ WARNING ]" << "\033[0m" << std::endl;
	std::cout << "I think I deserve to hace some extra bacon for free. I've been coming for years whereas you started working here last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[31m" "[ ERROR ]" << "\033[0m" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
}