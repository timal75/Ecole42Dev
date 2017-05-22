/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:04:03 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:42:25 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145,137), _target ("") 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145,137), _target(target) 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &frt)
{
	*this = frt;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &frt)
{
	this->_target = frt._target;
	return (*this);
}

void ShrubberyCreationForm::action(void) const
{
	std::string fo;
	std::ofstream output;

	fo = this->_target + "_shrubbery";
	output.open(fo);
	output << "ASCII trees" << std::endl;
	output.close ();
}

