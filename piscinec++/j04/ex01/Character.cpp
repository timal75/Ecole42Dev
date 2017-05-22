/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:43:58 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:44:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character() : name(""), ap(40), weapon(NULL)
{
}

Character::Character(std::string const &name) : name(name), ap(40), weapon(NULL)
{
}

Character::Character(Character const &src) : name(src.name), ap(40), weapon(NULL)
{
}

Character::~Character()
{
}

Character	&Character::operator=(Character const &rhs)
{
	this->name = rhs.name;
	this->ap = rhs.ap;
	this->weapon = rhs.weapon;
	return (*this);
}

void		Character::recoverAP()
{
	if (ap + 10 > 40)
		ap = 40;
	else
		ap += 40;
}

void		Character::equip(AWeapon *weapon)
{
	this->weapon = weapon;
}

void		Character::attack(Enemy *enemy)
{
	if (weapon != NULL)
	{
		if (ap < weapon->getAPCost())
			return;
		std::cout	<< name << " attacks " << enemy->getType() << " with a "
					<< weapon->getName() << std::endl;
		weapon->attack();
		enemy->takeDamage(weapon->getDamage());
		ap -= weapon->getAPCost();
	}
}

std::string const	Character::getName() const
{
	return (name);
}

int					Character::getAP() const
{
	return (ap);
}

const AWeapon		*Character::getWeapon() const
{
	return (weapon);
}

std::ostream	&operator<<(std::ostream &o, Character const &rhs)
{
	o	<< rhs.getName() << " has " << rhs.getAP() << " AP and ";
	if (rhs.getWeapon() == NULL)
		o << "is unarmed";
	else
		o << "weilds a " << rhs.getWeapon()->getName();
	return (o << std::endl);
}
