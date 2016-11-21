/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tailleCarre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:14:07 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 16:18:11 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int		essaietendre(char **tab, int *carre, int *val, int taille)
{
	int	res;

	if (val[3] == (carre[3] + taille) && val[4] == carre[4] + taille)
		if ((res = etendrecarre(tab, carre, taille, val)))
		{
			return (res);
		}
		else
			return (taille);
	else
		return (0);
}

void	initc(int *carre, int *bon, int *i, int *j)
{
	*i = carre[3];
	*j = carre[4];
	*bon = 1;
}

int		taillecarre(char **tab, int *carre, int nb_lignes, int nb_col)
{
	int		bon;
	int		i;
	int		j;
	int		taille;
	int		val[5];

	initc(carre, &bon, &i, &j);
	taille = carre[0] + 1;
	while (bon && i < nb_lignes && i < carre[3] + taille)
	{
		j = carre[4];
		while (bon && j < nb_col && j < carre[4] + taille)
		{
			if (tab[i][j] == '1')
				bon = 0;
			else
				j++;
		}
		i++;
	}
	val[0] = nb_lignes;
	val[1] = nb_col;
	val[3] = i;
	val[4] = j;
	return (essaietendre(tab, carre, val, taille));
}
