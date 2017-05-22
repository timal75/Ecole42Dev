/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:44:09 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:44:12 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	std::string name;
	int			ap;
	AWeapon		*weapon;

	Character();

public:
	Character(std::string const &name);
	Character(Character const & src);
	virtual ~Character();

	Character		&operator=(Character const &rhs);

	void				recoverAP();
	void				equip(AWeapon*);
	void				attack(Enemy*);
	std::string const	getName() const;
	int					getAP() const;
	const AWeapon		*getWeapon() const;
};

std::ostream	&operator<<(std::ostream &lhs, Character const &rhs);

#endif
