/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:12:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 18:17:08 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main (void)
{
	Zombie  zom1 ("Zombie1", "ugly");
	ZombieEvent	 ze1;
	Zombie       *ze2;

	ze1.setZombieType("big and ugly");
	ze2 = ze1.newZombie("toto");
	ze2->announce ();
	delete ze2;

	ze1.randomChump ();
	ze1.randomChump ();
	ze1.randomChump ();
	ze1.randomChump ();

	zom1.announce ();
	return (0);
}
