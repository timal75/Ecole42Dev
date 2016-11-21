/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikacumi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 16:04:18 by ikacumi           #+#    #+#             */
/*   Updated: 2016/09/18 17:28:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_check1(int *tab, char *str, int i)
{
	int	h;
	int	v;
	int	x;
	int	y;

	x = tab[0];
	y = tab[1];
	h = tab[2];
	v = tab[3];
	if (((h == 0 && v == 0) || (h == x - 1 && v == y)) ||
			(h == x - 1 && v == y - 1))
		str[i] = ('/');
	else if ((v == y - 1 && h == 0) || ((h == x - 1 && v == 0) ||
				(h == x && v == y - 1)))
		str[i] = ('\\');
	else if (h == 0 || v == 0 || h == x - 1 || v == y - 1)
		str[i] = ('*');
	else
		str[i] = (' ');
	return (str);
}

char	*colle01(int x, int y)
{
	char	*str;
	int		i;
	int		tab[4];

	i = 0;
	tab[0] = x;
	tab[1] = y;
	tab[2] = 0;
	tab[3] = 0;
	str = (char *)malloc(sizeof(char) * ((x * y) + 1));
	while (tab[3] < tab[1])
	{
		while (tab[2] < tab[0])
		{
			str = ft_check1(tab, str, i);
			i++;
			tab[2]++;
		}
		str[i] = ('\n');
		i++;
		tab[2] = 0;
		tab[3]++;
	}
	str[i] = '\0';
	return (str);
}
