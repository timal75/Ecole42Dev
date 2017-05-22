/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:54:52 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/12 01:15:31 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <string>
#include <iostream>
#include <sstream>

Human::Human () : _name("bob"),_brain () 
{
}

Human::~Human ()
{
}

Brain &Human::getBrain ()
{
	const void * address5 = static_cast<const void*>(&(Human::_brain));
	std::stringstream ss5;
	ss5 << address5;
	std::cout << "ds getbrain : " << ss5.str() << std::endl;
	return (Human::_brain);
}

std::string Human::identify ()
{
	const void * address = static_cast<const void*>(&(this->_brain));
	std::stringstream ss;
	ss << address;
	std::cout << "this->brain : " << ss.str() << std::endl;
	const void * address1 = static_cast<const void*>(&(Human::_brain));
	std::stringstream ss1;
	ss1 << address1;
	std::cout << "human::brain : " << ss1.str() << std::endl;
	    return (ss.str());
}
