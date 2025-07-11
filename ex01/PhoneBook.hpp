/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-10 10:45:29 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-10 10:45:29 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		count;
		int		oldIndex;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact(Contact newContact);
		void displayContacts() const;
		void displayContact(int i) const;
		void search() const;
		Contact getContact(int i) const;
};

#endif