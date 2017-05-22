/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:43:26 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/18 23:08:18 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convert.hpp"

int main (int argc, char **argv)
{
	std::string   input;

	if (argc != 2)
	{
		std::cout << "Wrong number of Parameters !." << std::endl;
		return (1);
	}
	input = argv[1];
	Convert cv (input);
	cv.print ();
	
}
