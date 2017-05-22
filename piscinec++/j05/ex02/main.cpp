/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:33:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:18:22 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(0));
	Bureaucrat b1;
	Bureaucrat b2("test", 125);


	std::cout << b1 << std::endl << b2 << std::endl;
	try
	{
		Bureaucrat b3("test2", 185);
		std::cout << b3 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b4("test3", 0);
		std::cout << b4 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat b5("Test", 1);
	Bureaucrat b6("Last Test", 150);
	try
	{
		b5.increase();
		std::cout << b5 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b6.decrease();
		std::cout << b6 << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	PresidentialPardonForm f1("Test");
	PresidentialPardonForm f2("Test2");
	b6.signForm(f1);
	b5.signForm(f1);
	b5.signForm(f1);
	b6.executeForm(f1);
	b5.executeForm(f2);
	b5.executeForm(f1);

	ShrubberyCreationForm f3("Test");
	ShrubberyCreationForm f4("Test2");
	b6.signForm(f3);
	b5.signForm(f3);
	b5.signForm(f3);
	b6.executeForm(f3);
	b5.executeForm(f4);
	b5.executeForm(f3);

	RobotomyRequestForm f5("Test");
	RobotomyRequestForm f6("Test2");
	b6.signForm(f5);
	b5.signForm(f5);
	b5.signForm(f5);
	b6.executeForm(f5);
	b5.executeForm(f6);
	b5.executeForm(f5);

}
