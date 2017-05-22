/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:36:16 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/12 20:11:53 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class Fixed {

	public 	: 
			Fixed (void);
			~Fixed (void);
			Fixed (Fixed const &fixed);
			Fixed &operator=(Fixed const &fixed);
			int getRawBits (void) const;
			void setRawBits (int const raw);

	private :
			int _fixedpoint;
			static const int _fractbits;
};

#endif
