/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 20:52:09 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/06 14:14:13 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int		premier;
	int		trouve;
	int		i;

	premier = 1;
	trouve = 0;
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

int ft_find_next_prime(int nb)
{
	int 	is_prime;
	int		i;

	i =nb + 1;
	is_prime = ft_is_prime(i);
	while (is_prime == 0)
	{
		i++;
		//printf("i  %d\n", i);
		is_prime = ft_is_prime(i);
		printf("retour fonction i :  %d  fonction %d\n", i, is_prime);
	}
	return(i);
}
int main (void)
{
	int		x;
	int		resultat;

	x = 25;
	//resultat = ft_is_prime(x);
	resultat = ft_find_next_prime(x);
	printf("Le resultat est %d\n", resultat);
	resultat = ft_is_prime(resultat);
	printf("Le 2eme resultat est %d\n", resultat);
}
