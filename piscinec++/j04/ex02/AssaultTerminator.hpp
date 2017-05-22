/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:47:13 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:47:15 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AssaultTerminator_HPP
# define AssaultTerminator_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const & src);
	virtual ~AssaultTerminator();

	AssaultTerminator		&operator=(AssaultTerminator const &rhs);

	ISpaceMarine		*clone() const;
	void				battleCry() const;
	void				rangedAttack() const;
	void				meleeAttack() const;
};

#endif
