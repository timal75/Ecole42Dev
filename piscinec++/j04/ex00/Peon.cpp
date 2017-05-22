/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:41:13 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:41:22 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon() : Victim("")
{
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src)
{
	*this = src;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon		&Peon::operator=(Peon const &rhs)
{
	Victim::operator=(rhs);
	return (*this);
}

void		Peon::getPolymorphed() const
{
	std::cout	<< getName() << " has been turned into a pink pony !"
				<< std::endl;
}
