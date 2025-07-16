/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-10 11:51:54 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-10 11:51:54 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

std::string promptNonEmptyField(const std::string& prompt)
{
	std::string input;
	do
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit (0);
		if (input.empty())
			std::cout << "Field cannot be empty. Please enter again." << std::endl;
	} while (input.empty());
	return (input);
}

int	main()
{
	PhoneBook pb;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command == "ADD")
		{
			Contact newContact;
			newContact.setFirstName(promptNonEmptyField("Enter first name: "));
			newContact.setLastName(promptNonEmptyField("Enter last name: "));
			newContact.setNickname(promptNonEmptyField("Enter nickname: "));
			newContact.setPhoneNumber(promptNonEmptyField("Enter phone number: "));
			newContact.setDarkestSecret(promptNonEmptyField("Enter darkest secret: "));
			pb.addContact(newContact);
		}
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
		{
			std::cout << "Exiting phonebook. Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}
