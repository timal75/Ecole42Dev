/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:10:33 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/19 15:59:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

template <typename T ,typename L>
void iter (T *tab, L len, void (*fn)(T &))
{
	L i;

	i = 0;
	while (i < len)
	{
		fn(tab[i]);
		i++;
	}
}

template <typename T>
void	add(T &i)
{
		i = i +34;
}

template <typename T>
void	print(T &i)
{
		std::cout << i << " ";
}

int main(void)
{
	int 	i;
	int		tab[5];
	double	tab1[5];
	char	tab2[5];
	
	i = 0;
	while(i <= 4)
	{
		tab[i] = i;
		i++;
	}

	iter(tab, 5, add);
	iter(tab, 5, print);

	i = 0;
	while(i <= 4)
	{
		tab1[i] = i;
		i++;
	}

	iter(tab1, 5, add);
	iter(tab1, 5, print);

	i = 0;
	while(i <= 4)
	{
		tab2[i] = i;
		i++;
	}

	iter(tab2, 5, add);
	iter(tab2, 5, print);
	return (0);
}
