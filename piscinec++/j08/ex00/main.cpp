/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:59:18 by jblancha          #+#    #+#             */
/*   Updated: 2017/02/27 20:59:12 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <list>
#include"easyfind.cpp" 

int	main(void)
{
	std::list<int>					lst;
	std::list<int>::iterator		it;

	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(13);
	lst.push_back(18);
	lst.push_front(25);

	 easyfind(lst, 15);
	 easyfind(lst, 25);
	 easyfind(lst, 10);
	 easyfind(lst, 100);

	return (0);
}
