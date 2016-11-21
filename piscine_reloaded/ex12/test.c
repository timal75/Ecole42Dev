/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:32:46 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/03 14:36:22 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_iterative_factorial(int nb)
{
	int	total;
	int	i;

	if (nb < 0)
		return (0);
	total = 1;
	i = 1;
	while ( i < nb)
	{
		total = total * i;
		printf("i : %d total : %d\n", i, total);
		i++;
	}
	return (total);
}
