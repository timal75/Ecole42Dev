/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:41:54 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:42:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : name(""), title("")
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
}

Sorcerer::~Sorcerer()
{
	std::cout	<< name << ", " << title << ", is dead. Consequences will never"
				<< " be the same !" << std::endl;
}

Sorcerer	&Sorcerer::operator=(Sorcerer const &rhs)
{
	this->name = rhs.name;
	this->title = rhs.title;
	return (*this);
}

std::string	Sorcerer::getName() const
{
	return (name);
}

std::string	Sorcerer::getTitle() const
{
	return (title);
}


void		Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream& operator<< (std::ostream& stream, const Sorcerer &sorcerer)
{
	stream	<< "I am " << sorcerer.getName() << ", " << sorcerer.getTitle()
			<< ", and I like ponies !" << std::endl;
	return (stream);
}
