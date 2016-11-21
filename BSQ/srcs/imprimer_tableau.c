/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprimer_tableau.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:18:14 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:29:24 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void	imprimer_tableau(char **tab, int nb_lignes, int nb_col)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb_lignes)
	{
		j = 0;
		while (j < nb_col)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
