/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:22:04 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 22:27:57 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)  
{
}

Intern::~Intern(void)
{
}

Intern::Intern(Intern const &frt)
{
	*this = frt;
}

Intern &Intern::operator=(Intern const &)
{
	return (*this);
}

Intern::FormUnknown::FormUnknown(void)  
{
}

Intern::FormUnknown::FormUnknown(FormUnknown const &Ex)  
{
	*this = Ex; 
}

Intern::FormUnknown::~FormUnknown(void) throw () 
{
}

Intern::FormUnknown &Intern::FormUnknown::operator=(FormUnknown const &)  
{
	return (*this); 
}

Form *Intern::makeForm(std::string Name, std::string Target)
{
	if (Name == "robotomy request")
	{
		std::cout << "Intern creates Form " << Name << std::endl; 
		return (new RobotomyRequestForm(Target));
	}
	else if (Name == "presidential pardon request")
	{
		std::cout << "Intern creates Form " << Name << std::endl; 
		return (new PresidentialPardonForm(Target));
	}
	else if (Name == "shrubbery request")
	{
		std::cout << "Intern creates Form " << Name << std::endl; 
		return (new ShrubberyCreationForm(Target));
	}
	else
		throw (Intern::FormUnknown ());
}
