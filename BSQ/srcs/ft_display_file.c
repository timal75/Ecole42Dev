/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsangare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 19:17:06 by fsangare          #+#    #+#             */
/*   Updated: 2016/09/21 23:31:00 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		line1_ok(char *tab, char *carac)
{
	char 	nb_lignes[100];
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = 0;
	while (tab[j] != '\0')
	{
		if ((tab[j] >= '1' && tab[j] <= '9'))
		{
				nb_lignes[k] = tab[j];
				k++;
		}
		else
		{
			carac[i]	= tab[j];
			i++;
		}
		j++;
	}
		return (ft_atoi(nb_lignes));
}

void	operate2_tab(char **tab2,int nb_lignes, char *chartab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab2[i][j])
	{
		if (tab2[i][j] != chartab[0] || tab2[i][j] != chartab[1] || tab2[i][j] != chartab[2])
		{
			ft_putstr("CTRL 2-1 : File invalide\n");
			return;
		}
		if (tab2[i][j] == '\n')
		{
			if (j != nb_lignes - 1)
			{
				ft_putstr("CTRL 2-2 : File invalide\n");
				return;
			}
			j	= 0;
			i++;
		}
		else
		j++;
	}
	if (i != nb_lignes - 1)
	{
		ft_putstr("CTRL 2-3 : File invalide\n");
		return;
	}
	else
	{
	ft_putstr("CTRL 2 : File ok\n");
	//appel_pgm_line1_ok(tab, carac)jblancha(char **tab, int nb_lignes, char *chartab);
	}
}

void	operate_tab(char **tab, int x)
{
	char	**tab2;
	int		i;
	int		j;
	char	*carac;

	i = 0;
	j = 0;
	carac = NULL;

	tab2 = NULL;
	//tab2 = init(x, x);
	if ( 1 != 0)
	{
		while (tab[i][j])
  	{
			tab2[i][j] = tab[i + 1][j];
			ft_putchar(tab[i + 1][j]);
			if (tab[i + 1][j] == '\n')
			{
				j	= 0;
				i++;
			}
			else
				j++;
		}
 	if (char_ok(tab))
	{
			ft_putstr("CTRL 1 : File ok\n");
			operate2_tab(tab2, x, char_feed(tab, x));
		}
		else
			ft_putstr("CTRL 1-1 : File invalide\n");
	}
	else
		ft_putstr("CTRL 1-2 : File invalide\n");
}

int		feed_file(int fd, char *file, char *carac)
{
	char	buffer[2];
	char	*final;
	char	*tmp;
	int		total_size;
	int		ret;
	int		flag;
	int		nb_lignes;

	flag = 1;
	ret = 0;
	close(fd);
	total_size = 0;
	tmp = (char *)malloc(sizeof(char) * 1);
	final = (char *)malloc(sizeof(char) * 1);
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while ((ret = read(fd, &buffer, 1)) && flag) 
		{
			if (*buffer != '\n')
			{	
				tmp = (char *)malloc(sizeof(char) * ft_strlen(final));
				ft_strcpy(tmp, final);
				if (final)
					free(final);
				buffer[1] = '\0';
				total_size = total_size + 1;
				final = (char *)malloc(sizeof(char) * total_size);
				final = ft_strcat(tmp, buffer);
				if (tmp)
					free(tmp);
			}
			else
			  flag = 0;	
		}
		close(fd);
		tmp = (char *)malloc(sizeof(char) * ft_strlen(final));
		ft_strcpy(tmp, final);
		total_size = total_size + 1;
		final = (char *)malloc(sizeof(char) * total_size);
		buffer[0] = '\0';
		final = ft_strcat(tmp, buffer);
		if (tmp)
	  	free(tmp);
	}
	nb_lignes = line1_ok(final, carac); 
	return(nb_lignes);
}

void	read_file (char *file, int nb_lignes, char *carac)
{
		init(file, nb_lignes,nb_lignes, carac);
}

void	test_file(char *file)
{
	int	fd;
	int	nb_lignes;
	char	carac[3];
	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		nb_lignes = feed_file(fd, file, carac);
		read_file(file, nb_lignes,carac);
		close(fd);
	}
	else
		write(2, "Impossible to open the file\n", 28);
}
