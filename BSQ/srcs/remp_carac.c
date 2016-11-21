/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_carac.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 01:10:46 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:06:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void	remp_carac(char **tab, int nb_lignes, char vide, char obstacle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb_lignes)
	{
		j = 0;
		while (j < nb_lignes)
		{
			if (tab[i][j] == vide)
				tab[i][j] = '0';
			if (tab[i][j] == obstacle)
				tab[i][j] = '1';
			j++;
		}
		i++;
	}
}
