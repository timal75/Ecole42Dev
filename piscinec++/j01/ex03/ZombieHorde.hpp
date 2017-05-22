/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:02:52 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 18:13:54 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_CLASS_H
# define ZOMBIEHORDE_CLASS_H

#include <vector>
#include "Zombie.hpp"

class ZombieHorde {

	public	:
				ZombieHorde (int nb);
				~ZombieHorde (void);
				void randomChump (int nb);
				std::vector<Zombie*> zombie ;
				void announce ();

	private :
				std::string _type;
				int	_nb;
};

#endif
