/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 21:04:57 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 16:13:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp" 

Zombie::Zombie (std::string nom, std::string type) : _nom(nom) , _type(type)
{
	std::cout << "Zombie "<<_nom << " of type " << _type << " created\n\n";
}

Zombie::~Zombie ()
{
	std::cout << "Zombie "<<_nom <<" of type "<< _type << " killed\n\n";
}

void Zombie::announce (void)
{
	std::cout << " My name is "<<_nom <<" of type "<< _type << std::endl;
	std::cout << " and I am going to eat you !!\n\n";
}
