/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:45:34 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:45:36 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(src)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
}

RadScorpion	&RadScorpion::operator=(RadScorpion const &rhs)
{
	Enemy::operator=(rhs);
	return (*this);
}

void		RadScorpion::takeDamage(int dmg)
{
	if (getHP() <= 0)
		return;
	Enemy::takeDamage(dmg);
	if (getHP() <= 0)
		std::cout << "* SPROTCH *" << std::endl;
}
