/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:15:06 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 23:49:04 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H
#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp" 
#include "Bureaucrat.hpp" 
#include "Intern.hpp" 

class Form;
class Intern;
class Bureaucrat;

class OfficeBlock
{

	public:

		OfficeBlock(void);
		OfficeBlock(Intern *i, Bureaucrat *s, Bureaucrat *e);
		~OfficeBlock (void);
		void setIntern(Intern *i);
		void setSigner(Bureaucrat *s);
		void setExecuter(Bureaucrat *e);
		void doBureaucracy(std::string name, std::string target);

	private :

		Intern *_i;
		Bureaucrat *_s;
		Bureaucrat *_e;

	protected :
};

#endif
