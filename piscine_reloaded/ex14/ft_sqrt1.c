/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:53:22 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/04 21:59:08 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
	{
		printf(" i : %d, carre : %d nb : %d\n",i, i*i, nb);
		i++;
	}
		printf(" nb : %d", nb);
	if (i * i == nb)
		return (i);
	else
		return (0);
}
