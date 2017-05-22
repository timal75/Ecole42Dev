/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:47:20 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/20 22:12:02 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_H
# define ARRAY_H
#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array {

	public : class IndexTooLargeException : public std::exception
			 {
				 public:
					 IndexTooLargeException();
					 IndexTooLargeException(IndexTooLargeException const &Ex);
					 virtual ~IndexTooLargeException() throw ();
					 IndexTooLargeException &operator=(IndexTooLargeException const &);
					 virtual const char * what(void) const throw ()
					 {
						 return "Index Out of Range!!!";
					 }
			 };
	public:

			 Array(void);
			 Array(unsigned int n);
			 ~Array(void);
			 Array(Array const &array);
			 Array &operator=(Array const &array);
			 unsigned int getsize(void) const;
			 T &operator[](unsigned int n);

	private :

			 T *_array;
			 unsigned int _size;

	protected :

};

#include "Array.Class.cpp"

#endif

