/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:41:40 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:41:44 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	Peon();
public:
	Peon(std::string name);
	Peon(Peon const & src);
	virtual ~Peon();

	Peon		&operator=(Peon const &rhs);
	
	void getPolymorphed() const;
};

#endif
