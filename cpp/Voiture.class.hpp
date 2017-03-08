/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Voiture.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:31:05 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 18:46:32 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VOITURE_CLASS_H
# define VOITURE_CLASS_H

#include <string.h>

class Voiture {


public :

			Voiture (std::string marque, int nbportes, int annee);
			~Voiture (void);
	int		getnbportes(void) const;
	int		getannee(void) const;
	static	int		getnb(void); 
	void	setnbportes(int nbportes);
	void	setannee(int annee);

private :

	std::string	_marque;
	int			_nbportes;
	int			_annee;
	static	int _nb;
};

#endif
