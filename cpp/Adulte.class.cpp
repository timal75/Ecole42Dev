/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Personne.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:42:48 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:51:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Adulte.class.hpp"
#include "Voiture.class.hpp"

Adulte::Adulte (std::string nom, std::string prenom, int age, std::string marque, int nbportes, int annee)
    				: Personne(nom, prenom, age),_nbenfants (0), voiture(marque, nbportes,annee)
{
	std::cout << "objet Adulte  instanciee \n" ;
}

Adulte::~Adulte (void)
{
	std::cout << "objet Adulte des-instanciee \n" ;
}

int	Adulte::getnbvoiture (void) 
{
	return (voiture.getnb());
}

int	Adulte::getannee (void) const
{
	return (voiture.getannee());
}

int	Adulte::getnbenfants (void) const
{
	return (this->_nbenfants);
}

void	Adulte::setnbenfants (int	nbenfants)
{
	this->_nbenfants = nbenfants;
}

void	Adulte::setannee (int	annee)
{
	voiture.setannee(annee);;
}
