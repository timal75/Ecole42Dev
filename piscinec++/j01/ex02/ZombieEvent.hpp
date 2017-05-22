/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:02:52 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 16:16:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_CLASS_H
# define ZOMBIEEVENT_CLASS_H

#include "Zombie.hpp"

class ZombieEvent {

	public	:
				ZombieEvent (void);
				~ZombieEvent (void);
				void setZombieType(std::string type);
				Zombie *newZombie(std::string name);
				void randomChump ();

	private :
				std::string _type;
};

#endif
