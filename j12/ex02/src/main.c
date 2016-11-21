/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 23:02:01 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 23:02:05 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	int i;
	int cpt;

	i = 3;
	cpt = 0;
	if (ac > 2)
	{
		if (ft_strcmp(av[1], "-c") == 0)
		{
			if (ft_atoi(av[2]) > 0)
			{
				while (i < ac)
				{
					ft_tail(ac, av[i], ft_atoi(av[2]), &cpt);
					i++;
				}
			}
		}
	}
	return (1);
}
