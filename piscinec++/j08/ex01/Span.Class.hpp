/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:18:33 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/20 23:13:09 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Span {

	public : class ArrayFullException : public std::exception
			 {
				 public:
					 ArrayFullException();
					 ArrayFullException(ArrayFullException const &Ex);
					 virtual ~ArrayFullException() throw ();
					 ArrayFullException &operator=(ArrayFullException const &);
					 virtual const char * what(void) const throw ()
					 {
						 return "Index FULL! You cannot add any more numbers.";
					 }
			 };

	public : class ArrayEmptyException : public std::exception
			 {
				 public:
					 ArrayEmptyException();
					 ArrayEmptyException(ArrayEmptyException const &Ex);
					 virtual ~ArrayEmptyException() throw ();
					 ArrayEmptyException &operator=(ArrayEmptyException const &);
					 virtual const char * what(void) const throw ()
					 {
						 return "Index EMPTY! Operation Not possible.";
					 }
			 };
	public :
			Span(int n);
			~Span(void);
			Span(Span const &sp);
			Span &operator=(Span const &sp);
			void addNumber(int nbr);
			int shortestSpan(void) ;
			int longestSpan(void); 

	private :
			size_t 				_size;
			std::vector<int>  	_array;	
			Span(void);
				
	protected :

};

#endif

