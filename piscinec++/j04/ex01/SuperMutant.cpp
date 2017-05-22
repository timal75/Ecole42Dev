/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:45:59 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:46:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
}

SuperMutant	&SuperMutant::operator=(SuperMutant const &rhs)
{
	Enemy::operator=(rhs);
	return (*this);
}

void		SuperMutant::takeDamage(int dmg)
{
	if (this->getHP() <= 0)
		return;

	dmg = dmg - 3 < 0 ? 0 : dmg - 3;
	Enemy::takeDamage(dmg);
	if (this->getHP() <= 0)
		std::cout << "Gaaah. Me want smash heads !" << std::endl;
}
