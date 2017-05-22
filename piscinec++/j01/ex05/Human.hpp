/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:46:45 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/12 01:15:51 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_H
# define HUMAN_H
#include "Brain.hpp"

class Human {

	public	:
				Human ();
				~Human ();
				std::string identify();
				Brain &getBrain();
	private :
				std::string _name;
				Brain _brain;
};
#endif
