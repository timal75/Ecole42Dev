/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 15:21:19 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/04 15:54:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_sqrt(int nb)
{
	int		trouve;
	int		nb1;
	int		nb2;

	nb1 = 1;
	nb2 = 1;
	trouve = 0;
	while ( trouve == 0 )
	{
		nb2 = 0.5 * ( nb1 + (nb/nb1));
		if (nb2 * nb2 == nb)
		{
			trouve = 1;
			nb1 = nb2;
		}
		else if (nb1 == nb2)
		{
			nb1 = 0;
			trouve = 1;
		}
		else
		{
			nb1 = nb2;
		}
	}
	return (nb1);
}

int main (void)
{
	int 	x;
	int		resultat;

	x = 30;
	resultat = ft_sqrt(x);
	printf("Le resultst est %d\n", resultat);
	return (0);
}
