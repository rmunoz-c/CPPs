/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-12 14:13:21 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-12 14:13:21 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
		public:
			Harl();
			~Harl();

			void complain(std::string level);
};

#endif