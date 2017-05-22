/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:15:06 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 22:25:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H
#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp" 

class Form;

class Intern
{

	public : class FormUnknown: public std::exception
		{
			public:
					FormUnknown();
					FormUnknown(FormUnknown const &Ex);
					virtual ~FormUnknown() throw ();
					FormUnknown &operator=(FormUnknown const &);
					virtual const char * what(void) const throw ()
					{
						return "Form Name is unknown";
					}
		};

	public:

		Intern(void);
		Intern(Intern const &frt);
		~Intern (void);
		Intern &operator=(Intern const &);
		Form *makeForm(std::string Name, std::string Target);

	private :

	protected :
};

#endif
