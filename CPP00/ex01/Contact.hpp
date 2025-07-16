/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-10 09:55:10 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-10 09:55:10 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();

		void setFirstName(std::string firstName);
		std::string getFirstName() const;

		void setLastName(std::string lastName);
		std::string getLastName() const;

		void setNickname(std::string nickname);
		std::string getNickname() const;

		void setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber() const;

		void setDarkestSecret(std::string darkestSecret);
		std::string getDarkestSecret() const;
};

#endif