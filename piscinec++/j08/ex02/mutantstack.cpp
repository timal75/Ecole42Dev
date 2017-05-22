/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:13:54 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/20 23:01:18 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &mutant)
{
	std::stack<T>::operator=(mutant);
	return (*this);
}

template <typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::begin(void)
{
	typename MutantStack<T>::Iterator	it;

	if (this->size() > 0)
	{
		it.setPtr(&this->top());
		std::advance(it, -this->size() + 1);
	}
	else
		it.setPtr(NULL);
	return (it);
}
template <typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::end(void)
{
	typename MutantStack<T>::Iterator	it;

	if (this->size() > 0)
		it.setPtr(&this->top() + 1);	
	else
		it.setPtr(NULL);
	return (it);	
}

template <typename T>
MutantStack<T>::Iterator::Iterator()
{
}

template <typename T>
MutantStack<T>::Iterator::~Iterator()
{
}

template <typename T>
MutantStack<T>::Iterator::Iterator(typename MutantStack<T>::Iterator const &it)
{
	Iterator::operator = (it);
	return ;
}

template<typename T>
typename MutantStack<T>::Iterator	&MutantStack<T>::Iterator::operator=(
	typename MutantStack<T>::Iterator const &it)
{
	std::iterator<std::bidirectional_iterator_tag, T>::operator=(it);
	_stk = it._stk;
	return (*this);
}

template<typename T>
bool MutantStack<T>::Iterator::operator!=(typename MutantStack<T>::Iterator const &it)
{
	return (_stk != it._stk);
}

template<typename T>
typename MutantStack<T>::Iterator	&MutantStack<T>::Iterator::operator++(void)
{
	_stk++;
	return (*this);
}

template<typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::Iterator::operator++(int)
{
	typename MutantStack<T>::Iterator	copy(*this);

	++copy;
	return (copy);
}

template<typename T>
typename MutantStack<T>::Iterator	&MutantStack<T>::Iterator::operator--(void)
{
	_stk--;
	return (*this);
}

template<typename T>
typename MutantStack<T>::Iterator	MutantStack<T>::Iterator::operator--(int)
{
	typename MutantStack<T>::Iterator	copy(*this);

	--copy;
	return (copy);
}

	template<typename T>
T &MutantStack<T>::Iterator::operator*(void)
{
	return (*_stk);
}

template<typename T>
void MutantStack<T>::Iterator::setPtr(T *ptr)
{
	this->_stk = ptr;
	return ;
}

template<typename T>
void MutantStack<T>::Iterator::printAdress(void)
{
	std::cout << (void*)_stk << std::endl;
	return ;
}
