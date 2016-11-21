/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lirefichier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 22:38:32 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/21 23:38:52 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lirefichier (char *file, char **tab, int nb_lignes, char *carac)
{
	char	buffer;
	int		fd;
	int		i;
	int		j;

	j = nb_lignes;
	buffer  = carac[0];
    fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return;
	}
	i = -1;
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buffer, 1))
  		{
			if (i >= 0)	
				tab[i][j] = buffer;
			if (buffer == '\n')
			{
				j	= 0;
				i++;
			}
			else
				j++;
		}
	}
	if (i <= 1)
		ft_putstr("CTRL 0-1 : File invalide\n");
	close(fd);
}
