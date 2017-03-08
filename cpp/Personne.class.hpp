/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persone.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:32:05 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 20:23:56 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONNE_CLASS_H
# define PERSONNE_CLASS_H

#include "Voiture.class.hpp"

class Personne {


public :

			Personne (std::string nom, std::string prenom, int age);
			~Personne (void);
	int		getage(void) const;
	static	int		getnb(void); 
	void	setage(int age);

private :

	std::string _nom;
	std::string _prenom;
	int		_age;
	static	int _nb;
};

#endif
