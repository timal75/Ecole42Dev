/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remettre_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 01:17:38 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:25:52 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void	remettre_carac(char **tab, int nb_lignes, char vide, char obstacle)
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
			if (tab[i][j] == '0')
				tab[i][j] = vide;
			if (tab[i][j] == '1')
				tab[i][j] = obstacle;
			j++;
		}
		i++;
	}
}
