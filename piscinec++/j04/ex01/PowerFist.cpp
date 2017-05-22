/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:45:08 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:45:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(PowerFist const &rhs) : AWeapon(rhs)
{
}

PowerFist::~PowerFist()
{
}

PowerFist	&PowerFist::operator=(PowerFist const &rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

void		PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
