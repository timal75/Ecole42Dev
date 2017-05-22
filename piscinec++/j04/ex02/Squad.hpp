/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:48:25 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:48:27 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
private:
	ISpaceMarine	**marines;
	int				count;
	int				arrLen;
public:
	Squad();
	Squad(Squad const & src);
	virtual ~Squad();

	Squad			&operator=(Squad const &rhs);
	int				getCount() const;
	ISpaceMarine	*getUnit(int) const;
	int				push(ISpaceMarine*);
};

#endif
