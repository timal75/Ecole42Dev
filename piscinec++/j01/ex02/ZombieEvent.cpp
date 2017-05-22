/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:16:53 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 18:16:28 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent ()
{
}


ZombieEvent::~ZombieEvent ()
{
}

void ZombieEvent::setZombieType(std::string type)
{
	ZombieEvent::_type = type; 
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->_type));
}	

void ZombieEvent::randomChump ()
{
	const char *names[] = {"Robert", "Albert", "Rodrigue","Christinne", "Anne", "Marie","Hubert","Hicham","Patrice"};
	int		i;
	static bool init = false;
	Zombie  *nz;

	if (!init)
	{
		srand ((unsigned int) time(NULL));
		init = true;
	}
	i = rand () % 9;
	nz = new Zombie(names[i], this->_type);
	nz->announce ();
	delete nz;

}

