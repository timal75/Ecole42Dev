/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:13:48 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 23:10:06 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H
#include <string>
#include "Weapon.hpp"

class HumanA{

	public :
			HumanA(std::string name, Weapon &weapon);
			~HumanA();
			void attack ();

	private :
		   	std::string _name;
			Weapon &_weapon;	

};

#endif
