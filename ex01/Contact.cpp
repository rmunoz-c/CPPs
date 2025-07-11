/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-10 09:54:57 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-10 09:54:57 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string	Contact::getFirstName() const
{
	return (this->firstName);
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string	Contact::getLastName() const
{
	return (this->lastName);
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string	Contact::getNickname() const
{
	return (this->nickname);
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}