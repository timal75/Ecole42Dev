/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:02:38 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/21 23:02:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Postion_H
# define Postion_H

#include <ft_gkrellm.hpp>

class Position {

		public :

					Position( void );
    				Position(int x, int y);
    				Position(Position const & pos);
    				virtual ~Position( void );
    				Position &operator=(Position const &pos);

    				bool operator==(Position const &pos) const;

    				int	getX() const;
    				int	getY() const;
    				void update(int const x, int const y);
    				std::string	toString(void) const;

		private:
    				int			_x;
    				int			_y;

    	protected :
};

std::ostream &	operator<<(std::ostream &o, Position const &pos);

#endif
