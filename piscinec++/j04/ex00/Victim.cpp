/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:42:25 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:42:28 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim() : name("")
{
}

Victim::Victim(std::string name) : name(name)
{
	std::cout	<< "Some random victim called " << name << " just popped !"
				<< std::endl;
}

Victim::Victim(Victim const &src)
{
	*this = src;
}

Victim::~Victim()
{
	std::cout	<< "Victim " << name << " just died for no apparent reason !"
				<< std::endl;
}

Victim		&Victim::operator=(Victim const &rhs)
{
	this->name = rhs.name;
	return (*this);
}

std::string	Victim::getName() const
{
	return (name);
}

void		Victim::getPolymorphed() const
{
	std::cout	<< name << " has been turned into a cute little sheep !"
				<< std::endl;
}

std::ostream& operator<< (std::ostream& stream, const Victim& victim)
{
	stream		<< "I'm " << victim.getName() << " and i like otters !"
				<< std::endl;
	return (stream);
}
