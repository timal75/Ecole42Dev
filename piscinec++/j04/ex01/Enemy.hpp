/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:44:30 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:44:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <string>

class Enemy
{
private:
	int			hp;
	std::string	type;
	Enemy();

public:
	Enemy(Enemy const &rhs);
	Enemy(int hp, std::string const &type);
	virtual ~Enemy();
	Enemy	&operator=(Enemy const &rhs);

	std::string const	getType() const;
	int getHP() const;

	virtual void takeDamage(int);
};

#endif
