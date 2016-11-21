/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 17:00:15 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/04 18:58:51 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int		premier;
	int		trouve;
	int		i;

	premier = 1;
	if ((nb == 1) || ( nb % 2 == 0))
	{
		premier = 0;
		trouve = 1;
	}
	else if ((nb == 2) || (nb == 3)) 
	{
		premier = 1;
		trouve = 1;
	}
	else
	{
		i = 3;
		while (( trouve == 0 ) && ( i < nb ))
		{
				if ((nb % i ) == 0)
				{
					trouve = 1;
					premier = 0;
				}
				i = i + 2;
			}
	}
	return (premier);
}

int main (void)
{
	int		x;
	int		resultat;

	x = 256569;
	resultat = ft_is_prime(x);
	printf("Le resultat est %d\n", resultat);
}
