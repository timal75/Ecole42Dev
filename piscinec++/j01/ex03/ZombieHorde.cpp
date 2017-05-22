/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:08:00 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 18:18:12 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde (int nb) : _nb(nb)
{
	this->_type = "Big ang Ugly";
	this->randomChump(_nb);
}


ZombieHorde::~ZombieHorde ()
{
	int		i;

	i = 0;
	while (i < this->_nb)
	{
		delete zombie[i];
		i++;
	}
}


void ZombieHorde::announce ()
{
	int		i;

	i = 0;
	while (i < this->_nb)
	{
		zombie[i]->announce ();
		i++;
	}

}
void ZombieHorde::randomChump (int nb)
{
	const char *names[] = {"Robert", "Albert", "Rodrigue","Christinne", "Anne", "Marie","Hubert","Hicham","Patrice"};
	int		i;
	static bool init = false; 
	Zombie  *nz;

	if (!init)
	{
		srand ((unsigned int)time(NULL));
		init = true;
	}
	while (nb >= 1)
	{
		i = rand () % 9;
		nz = new Zombie(names[i], this->_type);
		zombie.push_back(nz);
		nz->announce ();
		nb--;
	}
}

