/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 14:10:57 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/04 14:12:17 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int		x;

	x = 1;
	if (nb < 1)
	{
		x = 0;
	}
	while (nb > 1)
	{
		x = x * nb;
		nb--;
	}
	return (x);
}
int main (void)
{
	int		resultat;
	int		y;

	y = 15;

	resultat = ft_iterative_factorial(y);
	printf("Le resultat est :%d\n", resultat);
}
