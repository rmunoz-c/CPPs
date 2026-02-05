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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "\n=== TEST 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat paco("Paco", 137);
        ShrubberyCreationForm shrub("home");
        
        std::cout << paco << std::endl;
        std::cout << shrub << std::endl;

        std::cout << "\n--- Signing the form ---\n";
        paco.signForm(shrub);

        std::cout << "\n--- Executing signed form ---\n";
        paco.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat pepe("Pepe", 45);
        RobotomyRequestForm robot("Bender");
        
        std::cout << pepe << std::endl;
        std::cout << robot << std::endl;
        
        std::cout << "\n--- Signing the form ---\n";
        pepe.signForm(robot);
        
        std::cout << "\n--- Executing signed form ---\n";
        pepe.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat mariano("Mariano", 5);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << mariano << std::endl;
        std::cout << pardon << std::endl;
        
        std::cout << "\n--- Signing the form ---\n";
        mariano.signForm(pardon);
        
        std::cout << "\n--- Executing signed form ---\n";
        mariano.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4: Execute without signing ===" << std::endl;
    try {
        Bureaucrat agapito("Agapito", 1);
        ShrubberyCreationForm shrub2("garden");
        
        std::cout << agapito << std::endl;

        std::cout << "\n--- Attempting to execute unsigned form ---\n";
        agapito.executeForm(shrub2);  // Not signed!
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 5: Execute with insufficient grade ===" << std::endl;
    try {
        Bureaucrat eugenia("Eugenia", 50);
        PresidentialPardonForm pardon2("Zaphod");
        
        std::cout << eugenia << std::endl;

        std::cout << "\n--- Attempting to sign (insufficient grade) ---\n";
        eugenia.signForm(pardon2);  // Can't sign (needs 25)
        
        std::cout << "\n--- Attempting to execute ---\n";
        eugenia.executeForm(pardon2);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 6: Multiple robotomy attempts ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robot2("Employee");
        
        std::cout << "\n--- Signing the form ---\n";
        boss.signForm(robot2);
        
        std::cout << "\n--- Attempt 1 ---";
        boss.executeForm(robot2);
        
        std::cout << "\n--- Attempt 2 ---";
        boss.executeForm(robot2);
        
        std::cout << "\n--- Attempt 3 ---";
        boss.executeForm(robot2);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 7: Can sign but cannot execute ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 50);
        RobotomyRequestForm robot3("Target");
        
        std::cout << charlie << std::endl;
        std::cout << robot3 << std::endl;
        
        std::cout << "\n--- Signing the form ---\n";
        charlie.signForm(robot3);
        
        std::cout << "\n--- Attempting to execute (insufficient grade) ---\n";
        charlie.executeForm(robot3);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 8: One Bureaucrat, Multiple Forms ===" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        ShrubberyCreationForm shrub3("office");
        RobotomyRequestForm robot4("Android");
        PresidentialPardonForm pardon3("Convict");
        
        std::cout << ceo << "\n" << std::endl;
        
        std::cout << "--- Processing Shrubbery ---\n";
        ceo.signForm(shrub3);
        ceo.executeForm(shrub3);
        
        std::cout << "\n--- Processing Robotomy ---\n";
        ceo.signForm(robot4);
        ceo.executeForm(robot4);
        
        std::cout << "\n--- Processing Pardon ---\n";
        ceo.signForm(pardon3);
        ceo.executeForm(pardon3);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 9: Polymorphism with AForm pointers ===" << std::endl;
    try {
        Bureaucrat director("Director", 1);
        
        AForm *forms[3];
        forms[0] = new ShrubberyCreationForm("park");
        forms[1] = new RobotomyRequestForm("Robot");
        forms[2] = new PresidentialPardonForm("Prisoner");
        
        for (int i = 0; i < 3; i++)
        {
            std::cout << "\n--- Form " << (i + 1) << " ---\n";
            std::cout << *forms[i] << std::endl;
            
            std::cout << "Signing...\n";
            director.signForm(*forms[i]);
            
            std::cout << "Executing...\n";
            director.executeForm(*forms[i]);
        }
        
        std::cout << "\n--- Cleaning up ---\n";
        for (int i = 0; i < 3; i++)
            delete forms[i];
            
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 10: Copy constructor ===" << std::endl;
    try {
        ShrubberyCreationForm original("original");
        Bureaucrat signer("Signer", 100);
        
        std::cout << "\n--- Signing original ---\n";
        signer.signForm(original);
        
        std::cout << "\n--- Creating copy ---\n";
        ShrubberyCreationForm copy(original);
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;
        
        std::cout << "\n--- Executing copy ---\n";
        signer.executeForm(copy);
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed! ===" << std::endl;

    return (0);
}