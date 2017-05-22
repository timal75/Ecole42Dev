/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:43:35 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:43:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() : name(""), dmg(0), apcost(0)
{
}

AWeapon::AWeapon(AWeapon const &rhs) : name(rhs.name), dmg(rhs.dmg),
	apcost(rhs.apcost)
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int dmg) :
	name(name), dmg(dmg), apcost(apcost)
{
}

AWeapon::~AWeapon()
{
}

AWeapon		&AWeapon::operator=(AWeapon const &rhs)
{
	this->name = rhs.name;
	this->dmg = rhs.dmg;
	this->apcost = rhs.apcost;
	return (*this);
}

std::string	AWeapon::getName() const
{
	return (name);
}

int			AWeapon::getAPCost() const
{
	return (apcost);
}

int			AWeapon::getDamage() const
{
	return (dmg);
}
