/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:42:37 by jblancha          #+#    #+#             */
/*   Updated: 2017/02/27 21:00:02 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
void easyfind( T v, int n)
{
	typename T::iterator		it = v.begin();
	typename T::iterator		itend = v.end();

	while ( it != itend)
	{
		if (*it == n)
		{
			std::cout << "Found : " << *it << std::endl;
			return;
		}
		it++;
	}
	std::cout << " Not Found ! " << std::endl;
	return ;
}
