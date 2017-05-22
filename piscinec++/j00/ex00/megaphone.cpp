/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:34:28 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/09 15:50:46 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	int		i;
	int		c;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			c = argv[1][i];
			std::cout << (char)toupper(c);
			i++;
		}
		std::cout <<"\n";
	}
	
}
