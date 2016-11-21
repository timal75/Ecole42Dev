/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_tableau.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:19:27 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:12:04 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char		**remplir_tableau(char **tab, int *carre, char plein)
{
	int		i;
	int		j;

	i = carre[1];;
	while (i < (carre[1] + carre[0]))
	{
		j = carre[2];
		while (j < (carre[2] + carre[0]))
		{
			tab[i][j] = plein;
			j++;
		}
		i++;
	}
	return (tab);
}
