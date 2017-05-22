/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:42:38 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:42:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
	Victim();
	std::string	name;
public:
	Victim(std::string name);
	Victim(Victim const & src);
	virtual ~Victim();

	Victim		&operator=(Victim const &rhs);

	std::string	getName() const;

	virtual void getPolymorphed() const;
};

std::ostream& operator<< (std::ostream& stream, const Victim& victim);

#endif
