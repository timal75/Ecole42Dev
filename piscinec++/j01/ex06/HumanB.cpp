/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:05:03 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 21:08:13 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB (std::string name) : _name(name)
{
}


HumanB::~HumanB () 
{
}

void HumanB::attack ()
{
	std::cout <<this->_name << " attacks with weapon " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon (Weapon &weapon)
{
	this->_weapon = &weapon;
}
