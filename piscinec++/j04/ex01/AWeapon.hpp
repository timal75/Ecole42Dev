/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:43:46 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:43:49 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <string>

class AWeapon
{
private:
	std::string	name;
	int			dmg;
	int			apcost;

	AWeapon();
public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &rhs);
	AWeapon	&operator=(AWeapon const &rhs);

	virtual ~AWeapon();
	std::string virtual getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};

#endif
