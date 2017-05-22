/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:32:49 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 23:15:44 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS_H
# define PONY_CLASS_H

#include <iostream>
#include <string>

class Pony {

public :
				Pony (std::string nom);
				~Pony(void);
				void jump(int x);
private :
				std::string _nom;
};

#endif
