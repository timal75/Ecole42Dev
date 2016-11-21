/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsangare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 19:17:06 by fsangare          #+#    #+#             */
/*   Updated: 2016/09/21 17:47:13 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*char_feed(char **tab, int x)
{
	char 	*chartab;
	int		i;
	int		j;
	int		flag;
	int		flag2;

	i = 0;
	j = 0;
	flag = 0;
	flag2 = 0;
	chartab = NULL;
	if (!(chartab = (char*)malloc(sizeof(char) * x)))
		return (NULL);
	while (tab[i][j] && i < 1)
	{
		if ((tab[i][j] >= '1' && tab[i][j] <= '9') && flag == 0)
		{
				flag2 = 1;
		}
		else
		{
			flag++;
			if (flag2 == 1)
			{
				 chartab[flag - 1] = tab[i][j];
			}
		}
		if (tab[i][j] == '\n')
		{
			j	= 0;
			i++;
		}
		else
			j++;
	}
	return (chartab);
}

int		char_ok2(char *chartab)
{
	if ((chartab[0] != chartab[1]) && (chartab[1] != chartab[2]) && (chartab[0] != chartab[2]))
		return (0);
	else
		return (1);
}

int		char_ok(char **tab)
{
	char 	*chartab;
	int		i;
	int		j;
	int		flag;
	int		flag2;

	i = 0;
	j = 0;
	flag = 0;
	flag2 = 0;
	chartab = NULL;
	while (tab[i][j] && i < 1)
	{
		if ((tab[i][j] >= '1' && tab[i][j] <= '9') && flag == 0)
		{
				flag2 = 1;
		}
		else
		{
			flag++;
			if (flag2 == 1)
			{
				 chartab[flag - 1] = tab[i][j];
				 putchar(chartab[flag - 1]);
			}
		}
		if (tab[i][j] == '\n')
		{
			j	= 0;
			i++;
		}
		else
			j++;
	}
	putchar('\n');
	if (char_ok2(chartab))
		return (0);
	else
		return (1);
}
