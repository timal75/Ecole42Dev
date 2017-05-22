/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:57:45 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:45:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp" 

class Bureaucrat;

class Form
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

	public :class AlreadySignedException : public std::exception
		{
			public:
					AlreadySignedException();
					AlreadySignedException(AlreadySignedException const &);
					virtual ~AlreadySignedException() throw ();
					AlreadySignedException &operator=(AlreadySignedException const &Ex);
					virtual const char * what(void) const throw ()
			{
				return "Form already signed";
			}
		};

	public :class NotSignedException : public std::exception
		{
			public:
					NotSignedException();
					NotSignedException(NotSignedException const &);
					virtual ~NotSignedException() throw ();
					NotSignedException &operator=(NotSignedException const &Ex);
					virtual const char * what(void) const throw ()
			{
				return "Form not signed";
			}
		};

	public:

		Form(void);
		Form(std::string name, int gradetosign , int gradetoex);
		Form(Form const &frt);
		~Form (void);
		Form &operator=(Form const &frt);
		int getGradetosign (void) const;
		int getGradetoex (void) const;
		std::string getName(void) const;
		bool issigned(void) const;
		void beSigned(Bureaucrat const &buro);
		void execute (Bureaucrat const &buro);

	private :
		std::string _name;
		int			_gradetosign;
		int			_gradetoex;
		bool 		_issigned;

	protected :
	virtual void action() const = 0;
};
	std::ostream &operator<<(std::ostream &o, Form const &rhs);
#endif
