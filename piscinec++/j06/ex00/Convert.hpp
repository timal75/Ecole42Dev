/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:06:37 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/18 21:19:00 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <math.h>

class Convert 
{
	public :
	
			Convert (std::string input);
			~Convert ();
			void to_char (void);
			void to_int (void);
			void to_double (void);
			void to_float (void);
			void setchar (char c);
			void setint (int c);
			void setdouble (double c);
			void setfloat (float c);
			void print (void);

	private :

			std::string  _input;
			char  		 _char;
			bool		 _ischar;
			int 		 _int;
			bool		 _isint;
			double       _double;
			bool		 _isdouble;
			float  		 _float;
			bool		 _isfloat;


	protected :

};
