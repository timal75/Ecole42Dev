/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBloack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:22:04 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 23:47:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

OfficeBlock::OfficeBlock(void)  
{
}

OfficeBlock::~OfficeBlock(void)
{
}

OfficeBlock::OfficeBlock(Intern *i, Bureaucrat *s, Bureaucrat *e) : _i(i), _s(s),_e(e)
{
}

void OfficeBlock::setIntern(Intern *i)
{
	this->_i = i;
}

void OfficeBlock::setSigner(Bureaucrat *s)
{
	this->_s = s;
}

void OfficeBlock::setExecuter(Bureaucrat *s)
{
	this->_e = s;
}

void	OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	if (_i == NULL || _s == NULL || _e == NULL)
		return;
	Form *f = _i->makeForm(name, target);
		 _s->signForm(*f);
		_e->executeForm(*f);
}

