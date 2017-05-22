/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:15:06 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:56:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp" 

class Form;

class Bureaucrat
{

	public : class GradeTooHighException : public std::exception
		{
			public:
					GradeTooHighException();
					GradeTooHighException(GradeTooHighException const &Ex);
					virtual ~GradeTooHighException() throw ();
					GradeTooHighException &operator=(GradeTooHighException const &);
					virtual const char * what(void) const throw ()
					{
						return "Grade Too High";
					}
		};

	public :class GradeTooLowException : public std::exception
		{
			public:
					GradeTooLowException();
					GradeTooLowException(GradeTooLowException const &);
					virtual ~GradeTooLowException() throw ();
					GradeTooLowException &operator=(GradeTooLowException const &Ex);
					virtual const char * what(void) const throw ()
			{
				return "Grade Too Low";
			}
		};

	public:

		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &frt);
		~Bureaucrat (void);
		Bureaucrat &operator=(Bureaucrat const &frt);
		int getGrade (void) const;
		std::string getName(void) const;
		void increase (void);
		void decrease (void);
		void signForm(Form &fm);
		void executeForm(Form &fm);

	private :
		std::string _name;
		int	_grade;

	protected :
};
	std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
#endif
