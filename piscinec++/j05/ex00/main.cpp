/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:33:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/16 18:41:18 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat		buri ("Bureaucrat1", 1);
	Bureaucrat		buri1 ("Bureaucrat1", 150);

   std::cout << buri << buri1;
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
    std::cout << buri ;
	buri.decrease();
    std::cout << buri ;
	buri.increase();
    std::cout << buri ;
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 1);
    std::cout << buri ;
	buri.increase();
    std::cout << buri ;
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 150);
    std::cout << buri ;
	buri.decrease();
    std::cout << buri ;
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 151);
    std::cout << buri ;
	buri.decrease();
    std::cout << buri ;
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what () << std::endl;
	}
	try {
	Bureaucrat		buri ("Bureaucrat1", 0);
    std::cout << buri ;
	buri.decrease();
    std::cout << buri ;
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what () << std::endl;
	}
}
