/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:17:05 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:37:53 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void	lancerreste(char **tab, int nb_lignes, int nb_col, char *carac)
{

	remp_carac(tab, nb_lignes, carac[0], carac[1]);
	lancer_traitement(tab, nb_lignes, nb_col, carac);
}

void	init(char *file, int nb_lignes, int nb_col, char *carac)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * nb_lignes);
	if (!tab)
	{
		ft_putstr("memoire non allouee\n");
	}
	j = 0;
	while (i < nb_lignes)
	{
		tab[i] = (char *)malloc(sizeof(char) * nb_col);
		i++;
	}
	lirefichier(file, tab, nb_lignes, carac);
	lancerreste(tab, nb_lignes, nb_col, carac);
	i = 0;
	while (i < nb_lignes)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
