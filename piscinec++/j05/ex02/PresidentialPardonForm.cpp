/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:04:03 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:14:35 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("PresidentialPardonForm", 25, 5), _target ("") 
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &frt)
{
	*this = frt;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &frt)
{
	this->_target = frt._target;
	return (*this);
}

void PresidentialPardonForm::action(void) const
{
	std::cout << this->_target << " has been pardonned by Zafod Beeblebrox."<<std::endl;
}

