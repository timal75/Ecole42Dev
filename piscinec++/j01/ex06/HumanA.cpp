/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:05:03 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 20:35:23 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}


HumanA::~HumanA () 
{
}

void HumanA::attack ()
{
	std::cout <<this->_name << " attacks with weapon " << this->_weapon.getType () << std::endl;
}
