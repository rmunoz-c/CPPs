/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 11:26:51 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 11:26:51 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon){	
}

HumanA::~HumanA(){
}

void HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
