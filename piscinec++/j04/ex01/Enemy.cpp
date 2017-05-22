/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:44:19 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/14 21:44:22 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : hp(0), type("")
{
}

Enemy::Enemy(Enemy const &rhs) : hp(rhs.hp), type(rhs.type)
{
}

Enemy::Enemy(int hp, std::string const &type) : hp(hp), type(type)
{
}

Enemy::~Enemy()
{
}

Enemy		&Enemy::operator=(Enemy const &rhs)
{
	this->hp = rhs.hp;
	this->type = rhs.type;
	return (*this);
}

std::string const	Enemy::getType() const
{
	return type;
}

int			Enemy::getHP() const
{
	return hp;
}

void		Enemy::takeDamage(int dmg)
{
	if (hp - dmg < 0)
		hp = 0;
	else
		hp -= dmg;
}
