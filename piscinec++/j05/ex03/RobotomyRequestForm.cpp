/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:04:03 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/17 20:15:09 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("RobotomyRequestForm", 72, 45), _target ("") 
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) 
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &frt)
{
	*this = frt;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &frt)
{
	this->_target = frt._target;
	return (*this);
}

void RobotomyRequestForm::action(void) const
{
	static bool init = false;
	int nb;

	if (!init)
	{
		init = true;
		srand ((unsigned int) time(NULL));
	}
	std ::cout << "Make Some drilling noise" << std::endl;
	nb = rand () % 2;
	if (nb == 0)
		std ::cout << "Robot has been successfully Robotized." << std::endl;
	else
		std ::cout << "Failure !!!" << std::endl;;
}

