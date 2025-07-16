/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-16 13:16:44 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-16 13:16:44 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Pruebas de polimorfismo con AAnimal ---" << std::endl;

    AAnimal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    for (int i = 0; i < 4; ++i)
    {
        std::cout << animals[i]->getType() << " hace: ";
        animals[i]->makeSound();
    }

    std::cout << "\n--- Prueba de copia profunda con Dog ---" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "Cazar gatos");

    Dog copiedDog = originalDog;
    copiedDog.setIdea(0, "Dormir todo el día");

    std::cout << "OriginalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "CopiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n--- Prueba de copia profunda con Cat ---" << std::endl;
    Cat originalCat;
    originalCat.setIdea(0, "Cazar ratones");

    Cat copiedCat;
    copiedCat = originalCat;
    copiedCat.setIdea(0, "Romper cortinas");

    std::cout << "OriginalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
    std::cout << "CopiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << "\n--- Pruebas WrongAnimal y WrongCat ---" << std::endl;

    WrongAnimal* wrongAnimals[2];
    wrongAnimals[0] = new WrongAnimal();
    wrongAnimals[1] = new WrongCat();

    for (int i = 0; i < 2; ++i)
    {
        std::cout << wrongAnimals[i]->getType() << " hace: ";
        wrongAnimals[i]->makeSound();
    }

    for (int i = 0; i < 2; ++i)
        delete wrongAnimals[i];

    return 0;
}
