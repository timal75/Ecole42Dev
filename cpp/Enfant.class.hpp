/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persone.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:32:05 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:39:24 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENFANT_CLASS_H
# define ENFANT_CLASS_H

#include "Personne.class.hpp"

class Enfant : public Personne
{

public :

			Enfant (std::string nom, std::string prenom, int age);
			~Enfant (void);
	int		getnbjouet(void) const; 
	void	setnbjouet(int nbjouet);

private :

	int		_nbjouets;
};

#endif
