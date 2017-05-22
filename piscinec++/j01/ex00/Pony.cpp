/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:37:06 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 23:15:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Pony.hpp"

Pony::Pony (std::string nom) : _nom(nom)
{
	std::cout << "Pony " << _nom << " allocated" << std::endl; 
}


Pony::~Pony (void) 
{
	std::cout << "Pony " << _nom << " killed" << std::endl; 
}

void Pony::jump(int x)
{
	std::cout << "pony " << this->_nom << " just jumped "<< x << " times \n";
}
