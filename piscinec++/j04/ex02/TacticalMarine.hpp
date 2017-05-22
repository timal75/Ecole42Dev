/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:48:37 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:48:39 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const & src);
	virtual ~TacticalMarine();

	TacticalMarine		&operator=(TacticalMarine const &rhs);

	ISpaceMarine		*clone() const;
	void				battleCry() const;
	void				rangedAttack() const;
	void				meleeAttack() const;
};

#endif
