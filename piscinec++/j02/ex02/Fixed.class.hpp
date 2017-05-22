/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:36:16 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/12 23:07:24 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

	public 	: 
			Fixed (void);
			~Fixed (void);
			Fixed (Fixed const &fixed);
			Fixed (int const &fixed);
			Fixed (float const &fixed);
			Fixed &operator=(Fixed const &fixed);
			int getRawBits (void) const;
			int toInt(void) const;
			float toFloat(void) const;
			void setRawBits (int raw);
			bool operator>(Fixed const &fixed) const;
			bool operator<(Fixed const &fixed) const;
			bool operator>=(Fixed const &fixed) const;
			bool operator<=(Fixed const &fixed) const;
			bool operator==(Fixed const &fixed) const;
			bool operator!=(Fixed const &fixed) const;
			Fixed operator+(Fixed fixed);
			Fixed operator-(Fixed fixed);
			Fixed operator*(Fixed fixed);
			Fixed operator/(Fixed fixed);
			Fixed &operator++();
			Fixed &operator--();
			Fixed operator++(int);
			Fixed operator--(int);
			static Fixed &max(Fixed &fixed1, Fixed &fixed2);
			static const Fixed &max(Fixed const &fixed1, Fixed const &fixed2);
			static Fixed &min(Fixed &fixed1, Fixed &fixed2);
			static const Fixed &min(Fixed const &fixed1, Fixed const &fixed2);

	private :
			int _fixedpoint;
			static const int _fractbits;
};

std::ostream  &operator<<(std::ostream &o, Fixed const &fixed);
#endif
