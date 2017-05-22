/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.Class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:42:51 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/21 23:42:56 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Position.Class.hpp"

Position::Position(void) : _x(0), _y(0)
{
}

Position::Position(int x, int y) : _x(x), _y(y)
{
}

Position::~Position(void)
{
}

Position::Position(Position const &pos)
{
	this->_x = pos.getX();
	this->_y = pos.getY();
}

Position &Position::operator=(Position const &pos)
{
	this->_x = pos._x;
	this->_y = pos._y;
	return (*this);
}

bool Position::operator==(Position const &pos) const
{
	if ((this->_x == pos._x) &&
	(this->_y == pos._y))
		return (true);
	return(false);
}

int	Position::getX(void) const
{
	return(this->_x);
}

int	Position::getY(void) const
{
	return(this->_y);
}

void Position::update(const int x, const int y)
{
	this->_x = x;
	this->_y = y;
}

std::string	Position::toString(void) const {
    std::stringstream	buff;

    buff << "Position: x = " << this->_x <<"; y = "<< this->_y <<std::endl;
    return buff.str();
}

std::ostream &operator<<(std::ostream & o, Position const & rhs) {
    o << rhs.toString();
    return o;
}
