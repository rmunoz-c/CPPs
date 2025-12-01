/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 16:51:19 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-09-09 16:51:19 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CPP04 - Test Adaptado ===" << std::endl;

    // MateriaSource
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Character
    Character* hero = new Character("Hero");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    hero->equip(tmp);
    tmp = src->createMateria("cure");
    hero->equip(tmp);

    Character* enemy = new Character("Enemy");

    // Uso de materias
    std::cout << "\n-- Uso de materias --" << std::endl;
    hero->use(0, *enemy);
    hero->use(1, *enemy);

    // Test deep copy
    std::cout << "\n-- Copia profunda --" << std::endl;
    Character copyHero = *hero;
    copyHero.use(0, *enemy);
    copyHero.use(1, *enemy);

    // Test límites inventario
    std::cout << "\n-- Inventario lleno --" << std::endl;
    tmp = src->createMateria("ice");
    hero->equip(tmp);
    tmp = src->createMateria("cure");
    hero->equip(tmp);
    tmp = src->createMateria("ice"); // debería ignorarse
    hero->equip(tmp);

    // Test unequip
    std::cout << "\n-- Unequip --" << std::endl;
    hero->unequip(0);
    hero->use(0, *enemy); // no hace nada
    hero->use(1, *enemy); // sigue funcionando

    delete src;
    delete hero;
    delete enemy;

    std::cout << "\n✅ Todos los tests adaptados ejecutados correctamente." << std::endl;

    return 0;
}