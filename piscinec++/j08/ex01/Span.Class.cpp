/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.Class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:28:26 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/20 23:13:21 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.Class.hpp"

Span::Span(void)
{
}

Span::~Span(void)
{
}

Span::Span(int n)
{
	_size = n;
}

Span::Span(Span const &sp)
{
	(*this) = sp;
}

Span &Span::operator=(Span const &sp)
{
	_size = sp._size;
	this->_array = sp._array;
	return (*this);
}

void Span::addNumber(int nbr)
{
	if (this->_array.size() == _size)
	   throw (Span::ArrayFullException ());
	_array.push_back(nbr);;
}	

int Span::shortestSpan(void) 
{
	int		diff;
	int		diff1;
	size_t		i;

	if (this->_array.size() <= 1)
	   throw (Span::ArrayEmptyException ());
	std::sort(this->_array.begin (), this->_array.end() );
	diff = abs(_array[0] - _array[1]);
	i = 1;
	while (i < (_array.size () - 1))
	{
		diff1 = abs(_array[i] - _array[i + 1]);
		if (diff1 < diff)
			diff = diff1;
		i++;
	}
	return(diff);
}

int Span::longestSpan(void) 
{
	int		diff;
	int		diff1;
	size_t		i;

	if (this->_array.size() <= 1)
	   throw (Span::ArrayEmptyException ());
	std::sort(this->_array.begin (), this->_array.end() );
	diff = abs(_array[0] - _array[this->_array.size() - 1]);
	i = 1;
	while (i < (_array.size () - 1))
	{
		diff1 = abs(_array[i] - _array[i + 1]);
		if (diff1 > diff)
			diff = diff1;
		i++;
	}
	return(diff);
}

Span::ArrayFullException::ArrayFullException(void)
{
}

Span::ArrayFullException::ArrayFullException(ArrayFullException const &Ex)
{
		*this = Ex;
}

Span::ArrayFullException &Span::ArrayFullException::operator=(ArrayFullException const &)
{
		return (*this);
}

Span::ArrayFullException::~ArrayFullException(void) throw ()
{
}

Span::ArrayEmptyException::ArrayEmptyException(void)
{
}

Span::ArrayEmptyException::ArrayEmptyException(ArrayEmptyException const &Ex)
{
		*this = Ex;
}

Span::ArrayEmptyException &Span::ArrayEmptyException::operator=(ArrayEmptyException const &)
{
		return (*this);
}

Span::ArrayEmptyException::~ArrayEmptyException(void) throw ()
{
}

