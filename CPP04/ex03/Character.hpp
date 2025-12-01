
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 16:50:36 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-09-09 16:50:36 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include <string>
#include "ICharacter.hpp"

class AMateria;

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];


    public:
        Character();
        Character(std::string name);
        Character(const Character &c);
        Character &operator=(const Character &other);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif