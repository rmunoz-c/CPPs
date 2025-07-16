/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 11:17:47 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 11:17:47 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type){
}

Weapon::~Weapon(){
}

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
