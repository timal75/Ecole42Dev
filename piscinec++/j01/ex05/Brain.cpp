/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:39:42 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/12 00:53:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain ()
{
	_nbneurones = 2;
}

Brain::~Brain ()
{
}

std::string Brain::identify ()
{
	const void * address4 = static_cast<const void*>(this);
	std::stringstream ss4;
	ss4 << address4;
	return (ss4.str());
}
