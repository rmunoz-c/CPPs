/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-16 10:41:59 by rmunoz-c          #+#    #+#             */
/*   Updated: 2025-07-16 10:41:59 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const int numAnimals = 6;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; ++i)
    {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Sonidos de los animales ---\n";
    for (int i = 0; i < numAnimals; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Deep copy test con Dog ---\n";
    Dog originalDog;
    originalDog.setIdea(0, "Cazar gatos");
    std::cout << "OriginalDog idea[0]: " << originalDog.getIdea(0) << std::endl;

    Dog copiedDog(originalDog);
    copiedDog.setIdea(0, "Dormir todo el día");

    std::cout << "OriginalDog idea[0] tras cambiar copiedDog: " << originalDog.getIdea(0) << std::endl;
    std::cout << "CopiedDog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n--- Deep copy test con Cat ---\n";
    Cat originalCat;
    originalCat.setIdea(0, "Cazar ratones");
    std::cout << "OriginalCat idea[0]: " << originalCat.getIdea(0) << std::endl;

    Cat copiedCat;
    copiedCat = originalCat;
    copiedCat.setIdea(0, "Romper cortinas");

    std::cout << "OriginalCat idea[0] tras cambiar copiedCat: " << originalCat.getIdea(0) << std::endl;
    std::cout << "CopiedCat idea[0]: " << copiedCat.getIdea(0) << std::endl;

    std::cout << "\n--- Eliminando el array de animales ---\n";
    for (int i = 0; i < numAnimals; ++i)
        delete animals[i];

    std::cout << "\n--- Pruebas WrongAnimal y WrongCat ---\n";
    const WrongAnimal* metaWrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "wrongCat type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    metaWrong->makeSound();

    delete metaWrong;
    delete wrongCat;

    return (0);
}