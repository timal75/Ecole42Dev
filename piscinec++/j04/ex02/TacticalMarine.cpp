/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:48:13 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:48:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &src)
{
	(void)src;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine	&TacticalMarine::operator=(TacticalMarine const &rhs)
{
	(void)rhs;
	return (*this);
}

ISpaceMarine	*TacticalMarine::clone() const
{
	return new TacticalMarine();
}

void			TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void			TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}
