/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lancer_traitement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:25:06 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:30:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void	calcul_carre(char **tab, int *carre, int nb_lignes, int nb_col)
{
	int		taille;

	if ((tab[carre[3]][carre[4]] == '0') && carre[3] + carre[0] < nb_lignes
			&& carre[4] + carre[0] < nb_col)
	{
		taille = taillecarre(tab, carre, nb_lignes, nb_col);
		if (taille > carre[0])
		{
			carre[0] = taille;
			carre[1] = carre[3];
			carre[2] = carre[4];
		}
	}
}

void	lancer_traitement(char **tab, int nb_lignes, int nb_col, char *carac)
{
	int		carre[5];

	carre[0] = 0;
	carre[3] = 0;
	while (carre[3] < nb_lignes)
	{
		carre[4] = 0;
		while (carre[4] < nb_col && (carre[4] + carre[0] < nb_col))
		{
			calcul_carre(tab, carre, nb_lignes, nb_col);
			carre[4]++;
		}
		carre[3]++;
	}
	remettre_carac(tab, nb_lignes, carac[0], carac[1]);
	tab = remplir_tableau(tab, carre, carac[2]);
	imprimer_tableau(tab, nb_lignes, nb_col);
}
