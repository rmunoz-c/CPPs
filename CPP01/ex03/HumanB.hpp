/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 11:30:45 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 11:30:45 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;

	public:
		HumanB(const std::string& name);
		~HumanB();

		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif
