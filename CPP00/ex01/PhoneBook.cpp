/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-10 10:45:35 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-10 10:45:35 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(){
	this->count = 0;
	this->oldIndex = 0;
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::addContact(Contact newContact)
{
	this->contacts[this->oldIndex] = newContact;
	this->oldIndex = (this->oldIndex + 1) % 8;
	if (this->count < 8)
		this->count++;
	std::cout << "Contact added successfully. Total of contacts: "
			<< this->count << std::endl;
}

std::string	formatString(std::string str)
{
	if (str.length() <= 10)
		return (str);
	else
		return (str.substr(0, 9) + ".");
}

void PhoneBook::displayContacts() const
{
	if (this->count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10) << "Index" << "|"
        	<< std::right << std::setw(10) << "First Name" << "|"
        	<< std::right << std::setw(10) << "Last Name" << "|"
        	<< std::right << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::setfill('-') 
          << std::setw(10) << "" << "|"
          << std::setw(10) << "" << "|"
          << std::setw(10) << "" << "|"
          << std::setw(10) << "" << std::setfill(' ') << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << std::right << std::setw(10) << i + 1 << "|"
            	<< std::right << std::setw(10) << formatString(this->contacts[i].getFirstName()) << "|"
            	<< std::right << std::setw(10) << formatString(this->contacts[i].getLastName()) << "|"
            	<< std::right << std::setw(10) << formatString(this->contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int i) const
{
	if (i < 0 || i >= this->count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
		std::cout << "First Name: " << this->contacts[i].getFirstName() << std::endl;
		std::cout << "Last Name: " << this->contacts[i].getLastName() << std::endl;
		std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
		std::cout << "Phone Number: " << this->contacts[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << this->contacts[i].getDarkestSecret() << std::endl;
}

void PhoneBook::search() const
{
	int	index;

	if (this->count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
	this->displayContacts();
	std::string input;
	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, input);
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Invalid input: not a number." << std::endl;
			return ;
		}
	}
	std::stringstream ss(input);
    if (!(ss >> index) || !(ss.eof()))
    {
        std::cout << "Invalid input: conversion failed." << std::endl;
        return ;
    }
	if (index < 1 || index > this->count)
	{
		std::cout << "Invalid index: out of range." << std::endl;
		return ;
	}
	this->displayContact(index - 1);	
}