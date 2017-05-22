/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:47:38 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 20:43:54 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H
#include <string>

class Weapon {

	public :	
			Weapon (std::string type);
			~Weapon ();
			void setType(std::string  str);
			std::string getType ();

	private :
			std::string _type;

};

#endif
