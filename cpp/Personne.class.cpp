/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Personne.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:42:48 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:03:20 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Personne.class.hpp"

Personne::Personne (std::string nom, std::string prenom, int age)
    				: _nom(nom), _prenom(prenom) , _age(age)
{
	Personne::_nb += 1; 
	std::cout << "objet Personne instanciee \n" ;
}

Personne::~Personne (void)
{
	std::cout << "objet Personne des-instanciee \n" ;
}

int	Personne::getage (void) const
{
	return (this->_age);
}

int	Personne::getnb (void)
{
	return (Personne::_nb);
}

void	Personne::setage (int	age)
{
	this->_age = age;
}

int	Personne::_nb = 0;
