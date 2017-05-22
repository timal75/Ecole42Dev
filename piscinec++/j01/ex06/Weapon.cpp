/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:51:15 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 20:23:18 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type)
{
}

Weapon::~Weapon ()
{
}

void Weapon::setType(std::string str)
{
	this->_type = str;
}

std::string Weapon::getType()
{
	return (this->_type);
}
