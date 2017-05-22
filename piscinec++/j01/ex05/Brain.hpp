/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:35:09 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 23:09:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
#include <string>

class Brain {

	public :
			Brain ();
			~Brain ();
			std::string identify ();


	private : 
			int _nbneurones;

};

#endif
