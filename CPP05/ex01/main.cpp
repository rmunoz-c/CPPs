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
#include "Form.hpp"

int main()
{
    std::cout << "=== TEST 1: Creating valid forms ===" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        Form buildingPermit("Building Permit", 100, 75);
        
        std::cout << taxForm << std::endl;
        std::cout << buildingPermit << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: Invalid form grades ===" << std::endl;
    try {
        Form invalid1("Invalid High", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalid2("Invalid Low", 50, 151);
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: Successful signing ===" << std::endl;
    try {
        Bureaucrat paco("Paco", 30);
        Form contract("Employment Contract", 50, 25);
        
        std::cout << "Before signing: " << contract << std::endl;
        paco.signForm(contract);
        std::cout << "After signing:  " << contract << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Failed signing (grade too low) ===" << std::endl;
    try {
        Bureaucrat pepe("Pepe", 100);
        Form topSecret("Top Secret", 20, 10);
        
        std::cout << pepe << std::endl;
        std::cout << topSecret << std::endl;
        pepe.signForm(topSecret);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Edge case - exact grade ===" << std::endl;
    try {
        Bureaucrat mariano("Mariano", 50);
        Form report("Quarterly Report", 50, 30);
        
        mariano.signForm(report);
        std::cout << report << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Multiple signing attempts ===" << std::endl;
    try {
        Form memo("Important Memo", 75, 50);
        Bureaucrat agapito("Agapito", 50);
        Bureaucrat eugenia("Eugenia", 100);
        
        agapito.signForm(memo);
        eugenia.signForm(memo);
        
        std::cout << memo << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Copy constructor and assignment ===" << std::endl;
    try {
        Form original("Original", 50, 30);
        Bureaucrat signer("Signer", 40);
        
        signer.signForm(original);
        
        Form copy1(original);
        Form copy2("Temporary", 100, 80);
        copy2 = original;
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy1:    " << copy1 << std::endl;
        std::cout << "Copy2:    " << copy2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed! ===" << std::endl;

    return (0);
}