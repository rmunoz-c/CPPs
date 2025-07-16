/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 11:14:24 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 11:14:24 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string type;
	
		public:
			Weapon(const std::string& type);
			~Weapon();

			const std::string& getType() const;
			void setType(const std::string& type);
};

#endif