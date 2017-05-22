/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:33:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 23:58:14 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	Intern someRandomIntern;
	Form* rrf;
	Bureaucrat b1("test1", 125);
	Bureaucrat b2("test2", 1);
	Bureaucrat b3("test1", 12);

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
	OfficeBlock b(&someRandomIntern , &b1, &b2);
	b.doBureaucracy("robotomy request", "me");
	b.setSigner(&b3);
	b.doBureaucracy("robotomy request", "me");
}
	
