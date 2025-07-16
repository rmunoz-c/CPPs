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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	Dog originalDog;
	Dog copyDog(originalDog);
	Cat originalCat;
	Cat copyCat(originalCat);
	copyDog.makeSound();
	copyCat.makeSound();

	delete meta;
	delete j;
	delete i;

	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	for (int k = 0; k < 4; ++k)
    	animals[k]->makeSound();
	for (int k = 0; k < 4; ++k)
    	delete animals[k];

	std::cout << "\n--- Pruebas WrongAnimal y WrongCat ---\n" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();
	
	delete wrongMeta;
	delete wrongCat;
	
	WrongCat wrongOriginalCat;
	WrongCat wrongCopyCat(wrongOriginalCat);
	wrongCopyCat.makeSound();

	return (0);
}