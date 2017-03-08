/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Personne.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:42:48 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:45:06 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Personne.class.hpp"
#include "Enfant.class.hpp"

Enfant::Enfant (std::string nom, std::string prenom, int age)
    				: Personne(nom, prenom, age), _nbjouets (0)
{
	std::cout << "objet Enfant  instanciee \n" ;
}

Enfant::~Enfant (void)
{
	std::cout << "objet Enfant des-instanciee \n" ;
}

int	Enfant::getnbjouet (void) const
{
	return (this->_nbjouets);
}

void	Enfant::setnbjouet (int	nbjouet)
{
	this->_nbjouets = nbjouet;
}

