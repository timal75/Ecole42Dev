/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.Class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:47:42 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/19 18:42:24 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	_size = 0;
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
}

template <typename T>
Array<T>::~Array(void)
{
}

template <typename T>
Array<T>::Array(Array const &array)
{
	this->_size = array.getsize();
	this->_array = new T[this->_size];
	unsigned int i;
	i = 0;
	while (i < this->_size)
	{
		this->_array[i] = array._array[i];
		i++;
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &array)
{
	delete [] this->_array;
	this->_array = new T[array.getsize()];
	unsigned int i;
	i = 0;
	while (i < this->_size)
	{
		this->_array[i] = array._array[i];
		i++;
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::getsize(void) const
{
	return(this->_size);
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= this->getsize())
		throw (Array::IndexTooLargeException());
	return(this->_array[n]);
}

template <typename T>
Array<T>::IndexTooLargeException::IndexTooLargeException(void)
{
}

template <typename T>
Array<T>::IndexTooLargeException::IndexTooLargeException(IndexTooLargeException const &Ex)
{
		*this = Ex;
}

template <typename T>
typename Array<T>::IndexTooLargeException &Array<T>::IndexTooLargeException::operator=(IndexTooLargeException const &)
{
		return (*this);
}

template <typename T>
Array<T>::IndexTooLargeException::~IndexTooLargeException(void) throw ()
{
}

