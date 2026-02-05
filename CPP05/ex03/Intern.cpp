/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-04 21:11:09 by rmunoz-c          #+#    #+#             */
/*   Updated: 2026-02-04 21:11:09 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	FormCreator creators[] = 
	{
		{"shrubbery creation", &Intern::createShrubberyForm},
		{"robotomy request", &Intern::createRobotomyForm},
		{"presidential pardon", &Intern::createPresidentialForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (creators[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i].creator(target);
		}
	}
	std::cout << "Error: Intern cannot create form '" << formName
			  << "' because it doesn't exist" << std::endl;
	return NULL;
}