/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:44:42 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:44:44 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &rhs) : AWeapon(rhs)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle	&PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

void		PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
