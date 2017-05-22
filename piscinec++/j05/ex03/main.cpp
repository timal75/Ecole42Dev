/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:33:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 23:00:55 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	Intern someRandomIntern;
	Form* rrf;
	Bureaucrat b1("test", 125);
	Bureaucrat b2("test", 1);

	try {
	rrf = someRandomIntern.makeForm("robotomy request", "toto");
	rrf = someRandomIntern.makeForm("presidential pardon request", "toto");
	rrf = someRandomIntern.makeForm("shrubbery request", "toto");
	rrf = someRandomIntern.makeForm("shrubbery request12", "toto");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
	rrf = someRandomIntern.makeForm("robotomy request", "toto");
	rrf->beSigned(b1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
	rrf = someRandomIntern.makeForm("robotomy request", "toto");
	rrf->beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
