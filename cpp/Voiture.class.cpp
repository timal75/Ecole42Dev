/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Voiture.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:35:13 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:46:09 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Voiture.class.hpp"

Voiture::Voiture (std::string marque, int nbportes, int annee) : _marque(marque), _nbportes(nbportes), _annee(annee)
{
	Voiture::_nb += 1; 
	std::cout << "objet Voiture instanciee \n" ;
}

Voiture::~Voiture (void)
{
	std::cout << "objet Voiture des-instanciee \n" ;
}

int	Voiture::getnbportes (void) const
{
	return (this->_nbportes);
}

int	Voiture::getannee (void) const
{
	return (this->_annee);
}

int	Voiture::getnb (void)
{
	return (Voiture::_nb);
}

void	Voiture::setnbportes (int	nbportes)
{
	this->_nbportes = nbportes;
}

void	Voiture::setannee (int	annee)
{
	this->_annee = annee;
}

int	Voiture::_nb = 0;
