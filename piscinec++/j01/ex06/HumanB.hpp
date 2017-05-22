/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:38:17 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 23:04:37 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H
#include <string>
#include "Weapon.hpp"

class HumanB{

	public :
			HumanB(std::string name);
			~HumanB();
			void attack ();
			void setWeapon(Weapon &weapon);

	private :
		   	std::string _name;
			Weapon *_weapon;	

};

#endif
