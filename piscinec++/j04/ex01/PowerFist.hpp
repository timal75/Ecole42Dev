/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:45:23 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:45:25 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
private:
	PowerFist(const PowerFist &rhs);
public:
	PowerFist();
	virtual ~PowerFist();
	PowerFist	&operator=(PowerFist const &rhs);

	void attack() const;
};


#endif
