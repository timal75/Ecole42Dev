/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:12:29 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 18:14:25 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main (void)
{
	Zombie  zom1 ("Zombie1", "ugly");
	ZombieHorde	 ze1(8);
	
	ze1.announce ();


	return (0);
}
