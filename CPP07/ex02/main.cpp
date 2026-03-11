/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-03-11 19:38:42 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-03-11 19:38:42 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "\n=== TEST 1: Constructor por defecto ===" << std::endl;
	{
		Array<int> empty;
		std::cout << "Tamaño del array vacío: " << empty.size() << std::endl;
	}

	std::cout << "\n=== TEST 2: Constructor con tamaño (int) ===" << std::endl;
	{
		Array<int> arr(5);
		std::cout << "Tamaño: " << arr.size() << std::endl;
		std::cout << "Valores iniciales (deben ser 0): ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "Modificando elementos..." << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i * 10;

		std::cout << "Valores modificados: ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 3: Constructor de copia (deep copy) ===" << std::endl;
	{
		Array<int> original(3);
		original[0] = 10;
		original[1] = 20;
		original[2] = 30;

		std::cout << "Array original: ";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl;

		Array<int> copy(original);
		std::cout << "Array copiado: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		std::cout << "Modificando la copia..." << std::endl;
		copy[0] = 999;

		std::cout << "Array original después de modificar copia: ";
		for (unsigned int i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << " (debe seguir siendo 10 20 30)" << std::endl;

		std::cout << "Array copiado: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << " (debe ser 999 20 30)" << std::endl;
	}

	std::cout << "\n=== TEST 4: Operador de asignación (deep copy) ===" << std::endl;
	{
		Array<int> arr1(3);
		arr1[0] = 100;
		arr1[1] = 200;
		arr1[2] = 300;

		Array<int> arr2(2);
		arr2[0] = 1;
		arr2[1] = 2;

		std::cout << "Antes de asignación:" << std::endl;
		std::cout << "arr1: ";
		for (unsigned int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i] << " ";
		std::cout << std::endl;

		std::cout << "arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		arr2 = arr1;

		std::cout << "Después de arr2 = arr1:" << std::endl;
		std::cout << "arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		std::cout << "Modificando arr2[0]..." << std::endl;
		arr2[0] = 777;

		std::cout << "arr1: ";
		for (unsigned int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i] << " ";
		std::cout << " (debe seguir siendo 100 200 300)" << std::endl;

		std::cout << "arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << " (debe ser 777 200 300)" << std::endl;
	}

	std::cout << "\n=== TEST 5: Excepciones (índice fuera de rango) ===" << std::endl;
	{
		Array<int> arr(3);
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;

		try
		{
			std::cout << "Accediendo a arr[2] (válido): " << arr[2] << std::endl;
			std::cout << "Accediendo a arr[10] (inválido)..." << std::endl;
			std::cout << arr[10] << std::endl;
			std::cout << "❌ No debería llegar aquí" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "✅ Excepción capturada: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== TEST 6: Array de strings ===" << std::endl;
	{
		Array<std::string> words(3);
		std::cout << "Tamaño: " << words.size() << std::endl;
		std::cout << "Valores iniciales (strings vacíos): \"";
		for (unsigned int i = 0; i < words.size(); i++)
			std::cout << words[i] << "\" \"";
		std::cout << "\"" << std::endl;

		words[0] = "Hello";
		words[1] = "from";
		words[2] = "Array";

		std::cout << "Después de asignar valores: ";
		for (unsigned int i = 0; i < words.size(); i++)
			std::cout << words[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "\n=== TEST 7: Array const (solo lectura) ===" << std::endl;
	{
		Array<int> arr(3);
		arr[0] = 10;
		arr[1] = 20;
		arr[2] = 30;

		const Array<int> constArr(arr);
		std::cout << "Array const: ";
		for (unsigned int i = 0; i < constArr.size(); i++)
			std::cout << constArr[i] << " ";
		std::cout << std::endl;
	}

	return (0);
}