/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:44:53 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:44:55 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
private:
	PlasmaRifle(const PlasmaRifle &rhs);
public:
	PlasmaRifle();
	virtual ~PlasmaRifle();
	PlasmaRifle	&operator=(PlasmaRifle const &rhs);

	void attack() const;
};

#endif
