/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 16:50:19 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-09-09 16:50:19 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this->type = type;
}

AMateria::~AMateria(){
    std::cout << "El material se ha acabado, cambia de dealer" << std::endl;
}

AMateria::AMateria(const AMateria &a){
    this->type = a.type;
}

AMateria &AMateria::operator=(const AMateria &other){
    this->type = other.type;
    return(*this);
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter&){
    std::cout << "* uses " << this->type << " *" << std::endl;
}