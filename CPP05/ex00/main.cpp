/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-04 17:23:42 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-02-04 17:23:42 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Test 1: Create valid Bureaucrat ===" << std::endl;
    try {
        Bureaucrat paco("Paco", 75);
        std::cout << paco << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try {
        Bureaucrat pepe("Pepe", 0);
        std::cout << pepe << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try {
        Bureaucrat mariano("Mariano", 151);
        std::cout << mariano << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment until exception ===" << std::endl;
    try {
        Bureaucrat agapito("Agapito", 2);
        std::cout << agapito << std::endl;
        agapito.incrementGrade();
        std::cout << "After increment: " << agapito << std::endl;
        agapito.incrementGrade(); // Should throw
        std::cout << "After increment: " << agapito << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement until exception ===" << std::endl;
    try {
        Bureaucrat eugenia("Eugenia", 149);
        std::cout << eugenia << std::endl;
        eugenia.decrementGrade();
        std::cout << "After decrement: " << eugenia << std::endl;
        eugenia.decrementGrade(); // Should throw
        std::cout << "After decrement: " << eugenia << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}