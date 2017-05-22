/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:42:12 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:42:16 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

class Sorcerer
{
	std::string	name;
	std::string	title;
	Sorcerer();
	
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & src);
	virtual ~Sorcerer();

	std::string	getName() const;
	std::string	getTitle() const;
	Sorcerer		&operator=(Sorcerer const &rhs);

	void			polymorph(Victim const &victim) const;
};

std::ostream& operator<< (std::ostream& stream, const Sorcerer& sorcerer);

#endif
