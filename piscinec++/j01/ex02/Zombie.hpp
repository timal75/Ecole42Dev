/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 20:51:23 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 16:07:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>

class Zombie {

public :

		Zombie(std::string nom, std::string type);
		~Zombie (void);
		void announce(void);

private :

		std::string _nom;
		std::string _type;
};

#endif
