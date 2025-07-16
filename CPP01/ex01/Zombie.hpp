/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-11 14:29:43 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-11 14:29:43 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

	void announce(void);
	void setName(std::string name);
};

#endif