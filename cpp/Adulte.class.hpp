/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persone.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:32:05 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:52:13 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADULTE_CLASS_H
# define ADULTE_CLASS_H
#include "Personne.class.hpp"
#include "Voiture.class.hpp"

class Adulte : public Personne
{

public :

			Adulte (std::string nom, std::string prenom, int age, std::string marque, int nbportes, int annee);
			~Adulte (void);
	int		getnbvoiture(void) ; 
	int		getnbenfants(void) const; 
	int		getannee(void) const; 
	void	setnbenfants(int nbenfants) ; 
	void	setannee(int annee) ; 

private :

	int		_nbenfants;
	Voiture	voiture;
};

#endif
