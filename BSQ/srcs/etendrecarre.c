/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etendrecarre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:13:17 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 01:09:07 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int		etendrecarre2(char **tab, int *carre, int taille, int *val)
{
	int		res;
	int		bon;

	bon = val[2];
	if (bon)
	{
		if ((res = etendrecarre(tab, carre, taille + 1, val)))
			return (res);
		else
			return (taille);
	}
	else
		return (0);
}

int		valeurj(int bon, int j)
{
	if (bon)
		return (j--);
	else
		return (j);
}

void	initetendre(int *carre, int taille, int *i, int *j)
{
	*i = carre[3] + taille - 1;
	*j = carre[4];
}

int		etendrecarre(char **tab, int *carre, int taille, int *val)
{
	int		bon;
	int		i;
	int		j;

	bon = 1;
	initetendre(carre, taille, &i, &j);
	if (carre[3] + taille > val[0] || carre[4] + taille > val[1])
		return (0);
	while (bon && j < carre[4] + taille)
	{
		if (tab[i][j] == '1')
			bon = 0;
		else
			j++;
	}
	j = valeurj(bon, j);
	while (bon && i >= carre[3])
	{
		if (tab[i][j] == '1')
			bon = 0;
		else
			i--;
	}
	val[2] = bon;
	return (etendrecarre2(tab, carre, taille, val));
}
