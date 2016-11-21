/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsangare <fsangare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:07:39 by fsangare          #+#    #+#             */
/*   Updated: 2016/09/21 22:13:34 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	operate_tab_stdin(char *tab)
{
	char	**tab2;
	int 	pos;
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	pos = 0;
	tab2 = NULL;
	//tab2 = init (100, 100);
	if (tab[0] == '\0')
	{
		ft_putstr("file invalide\n");
		return ;
	}
	while (tab[pos])
	{
		tab2[x][y] = tab[pos];
		if (tab[pos] != '\n')
		{
			y =0;
			x++;
		}
		else if (tab[pos] == '\n')
			y++;
		pos++;
	}
	tab2[x][y] = '\0';
	operate_tab(tab2, x);
}

void	read_input(void)
{
	int		ret;
	int		total_size;
	char	buf[BUF_SIZE + 1];
	char	*tab;
	char	tmp[100000];

	total_size = 0;
	if (!(tab = malloc(1)))
		return ;
	while ((ret = read(0, buf, BUF_SIZE)) > 0)
	{
		if (ret == -1)
			return ;
		ft_strcpy(tmp, tab);
		buf[ret] = '\0';
		total_size = total_size + ret;
		if (!(tab = (char *)malloc(sizeof(char) * total_size)))
			return ;
		tab = ft_strcat(tmp, buf);
	}
	operate_tab_stdin(tab);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		read_input();
	else
		while (i < argc)
		{
			test_file(argv[i]);
			i++;
		}
	return (0);
}
