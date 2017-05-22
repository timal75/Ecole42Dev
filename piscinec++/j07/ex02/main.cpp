/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:19:12 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/19 19:07:04 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.Class.hpp"

int main(void)
{
	Array<int> a(11);
	Array<float> b(10);
	Array<char> c(10);

	size_t	i = 0;
	while (i < a.getsize())
	{
		a[i] = i;
		i++;
	}
	i = 0;
	while (i < a.getsize())
	{
		std::cout << a[i] << " ";
		i++;
	}
	i = 0;
	while (i < b.getsize())
	{
		b[i] = i + 2.25;
		i++;
	}
	i = 0;
	while (i < b.getsize())
	{
		std::cout << b[i] << " ";
		i++;
	}
	i = 0;
	while (i < c.getsize())
	{
		c[i] = i + 34;
		i++;
	}
	i = 0;
	try {
		while (i <= c.getsize())
		{
			std::cout << c[i] << " ";
			i++;
		}
	}
	catch(Array<char>::IndexTooLargeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
