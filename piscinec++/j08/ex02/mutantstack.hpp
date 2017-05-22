/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:32:56 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/20 22:59:09 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

#include <stack>
#include <iostream>
#include <string>


template<typename T>
class MutantStack : public std::stack<T> {

		public :

			class Iterator : public std::iterator<std::bidirectional_iterator_tag, T>
			{
				public:
					Iterator(void);
					Iterator(const Iterator &it); 
					~Iterator(void);
					Iterator &operator=(Iterator const &it);
					Iterator &operator++();
					Iterator operator++(int);
					Iterator &operator--();
					Iterator operator--(int);
					bool &operator==(const Iterator &it); 
					bool operator!=(const Iterator &it);
					T &operator*(void);
					void setPtr(T *ptr);
					void printAdress(void);
				
				private :
					T *_stk;

				protected :
			};

		public :

				MutantStack(void);
			
				MutantStack(MutantStack const &);
				MutantStack &operator=(MutantStack const &mutant);
				Iterator begin(void);
				Iterator end(void);	
				~MutantStack(void);				
		private :

		protected :

};
#include "mutantstack.cpp"

#endif
