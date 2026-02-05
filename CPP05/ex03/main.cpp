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
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "\n=== TEST 1: Intern creates ShrubberyCreationForm ===" << std::endl;
    {
        Intern intern;
        AForm *form;

        form = intern.makeForm("shrubbery creation", "home");
        
        if (form)
        {
            Bureaucrat bob("Bob", 137);
            std::cout << *form << std::endl;
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n=== TEST 2: Intern creates RobotomyRequestForm ===" << std::endl;
    {
        Intern intern;
        AForm *form;

        form = intern.makeForm("robotomy request", "Bender");
        
        if (form)
        {
            Bureaucrat alice("Alice", 45);
            std::cout << *form << std::endl;
            alice.signForm(*form);
            alice.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n=== TEST 3: Intern creates PresidentialPardonForm ===" << std::endl;
    {
        Intern intern;
        AForm *form;

        form = intern.makeForm("presidential pardon", "Arthur Dent");
        
        if (form)
        {
            Bureaucrat president("President", 1);
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
    }

    std::cout << "\n=== TEST 4: Invalid form name ===" << std::endl;
    {
        Intern intern;
        AForm *form;

        form = intern.makeForm("invalid form", "Target");
        
        if (!form)
        {
            std::cout << "→ Form was not created (NULL returned)" << std::endl;
        }
    }

    std::cout << "\n=== TEST 5: Multiple forms with one intern ===" << std::endl;
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        AForm *forms[3];

        forms[0] = someRandomIntern.makeForm("shrubbery creation", "garden");
        forms[1] = someRandomIntern.makeForm("robotomy request", "Robot");
        forms[2] = someRandomIntern.makeForm("presidential pardon", "Criminal");

        std::cout << std::endl;
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                std::cout << "--- Processing form " << (i + 1) << " ---" << std::endl;
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                std::cout << std::endl;
            }
        }

        // Cleanup
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
                delete forms[i];
        }
    }

    std::cout << "\n=== TEST 6: Case sensitivity check ===" << std::endl;
    {
        Intern intern;
        AForm *form;

        std::cout << "\n→ Trying 'Shrubbery Creation' (uppercase):" << std::endl;
        form = intern.makeForm("Shrubbery Creation", "test");
        if (!form)
            std::cout << "  NULL returned (expected - case sensitive)" << std::endl;

        std::cout << "\n→ Trying 'shrubbery creation' (lowercase):" << std::endl;
        form = intern.makeForm("shrubbery creation", "test");
        if (form)
        {
            std::cout << "  Form created successfully!" << std::endl;
            delete form;
        }
    }

    std::cout << "\n=== TEST 7: Multiple different interns ===" << std::endl;
    {
        Intern intern1;
        Intern intern2;
        Intern intern3;
        
        AForm* f1 = intern1.makeForm("shrubbery creation", "garden");
        AForm* f2 = intern2.makeForm("robotomy request", "android");
        AForm* f3 = intern3.makeForm("presidential pardon", "prisoner");
        
        std::cout << "\n→ All forms created by different interns!" << std::endl;
        
        if (f1) delete f1;
        if (f2) delete f2;
        if (f3) delete f3;
    }

    std::cout << "\n=== All tests completed! ===" << std::endl;

    return (0);
}