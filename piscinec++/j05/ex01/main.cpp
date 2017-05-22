/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:33:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 21:08:19 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat		buri ("Bureaucrat1", 1);
	Bureaucrat		buri1 ("Bureaucrat1", 150);
	Form			form1("Form1",25, 50);

   std::cout << buri << buri1;
   std::cout << form1;
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
	Form			form1("Form1",0, 50);
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " <<e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << e.what () << std::endl;
	}
   catch (Form::GradeTooHighException &e)
	{
		std::cout <<"Form "<< e.what () << std::endl;
	}
   catch (Form::GradeTooLowException &e)
	{
		std::cout << "Form  " <<e.what () << std::endl;
	}
   catch (Form::AlreadySignedException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
	Form			form2("Form1",20, 0);
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " <<e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << e.what () << std::endl;
	}
   catch (Form::GradeTooHighException &e)
	{
		std::cout <<"Form "<< e.what () << std::endl;
	}
   catch (Form::GradeTooLowException &e)
	{
		std::cout << "Form  " <<e.what () << std::endl;
	}
   catch (Form::AlreadySignedException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
	Form			form3("Form1",25, 200);
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " <<e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << e.what () << std::endl;
	}
   catch (Form::GradeTooHighException &e)
	{
		std::cout <<"Form "<< e.what () << std::endl;
	}
   catch (Form::GradeTooLowException &e)
	{
		std::cout << "Form  " <<e.what () << std::endl;
	}
   catch (Form::AlreadySignedException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
	Form			form4("Form1",250, 20);
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " <<e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << e.what () << std::endl;
	}
   catch (Form::GradeTooHighException &e)
	{
		std::cout <<"Form "<< e.what () << std::endl;
	}
   catch (Form::GradeTooLowException &e)
	{
		std::cout << "Form  " <<e.what () << std::endl;
	}
   catch (Form::AlreadySignedException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
	Form			form1("Form1",2, 50);
    std::cout << buri ;
    std::cout << form1;
	form1.beSigned(buri);
    std::cout << form1 ;
	form1.beSigned(buri);
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " <<e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << e.what () << std::endl;
	}
   catch (Form::GradeTooHighException &e)
	{
		std::cout <<"Form "<< e.what () << std::endl;
	}
   catch (Form::GradeTooLowException &e)
	{
		std::cout << "Form  " <<e.what () << std::endl;
	}
   catch (Form::AlreadySignedException &e)
	{
		std::cout << e.what () << std::endl;
	}
   try {
	Bureaucrat		buri ("Bureaucrat1", 25);
	Form			form1("Form1",25, 50);
    std::cout << buri ;
    std::cout << form1;
	form1.beSigned(buri);
    std::cout << form1 ;
	form1.beSigned(buri);
   }
   catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Bureaucrat " <<e.what () << std::endl;
	}
   catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Bureaucrat " << e.what () << std::endl;
	}
   catch (Form::GradeTooHighException &e)
	{
		std::cout <<"Form "<< e.what () << std::endl;
	}
   catch (Form::GradeTooLowException &e)
	{
		std::cout << "Form  " <<e.what () << std::endl;
	}
   catch (Form::AlreadySignedException &e)
	{
		std::cout << e.what () << std::endl;
	}
}
