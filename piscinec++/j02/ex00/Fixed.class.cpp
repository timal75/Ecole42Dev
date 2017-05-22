/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:49:15 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/12 20:11:58 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : _fixedpoint(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(Fixed const &fixed)
{
	this->_fixedpoint = fixed.getRawBits ();
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Assignation constructor called\n";
	this->_fixedpoint = fixed.getRawBits ();
	return (*this);
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits function called\n";
	return (this->_fixedpoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits function called\n";
	this->_fixedpoint = raw;
}

const int Fixed::_fractbits = 8;
