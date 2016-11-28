/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:39:35 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 02:32:05 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_checkstring(int count, char *str)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		if ((i % 5) < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#' && (++block > 4))
				return (0);
		}
		else
			if (str[i] != '\n')
				return (0);
		i++;
	}
		if ((count == 21) && str[20] != '\n')
		return (0);
	return (1);
}

int			ft_checkneighbor(char	*str)
{
	int		i;
	int		neighbor;

	neighbor = 0;
	i =0;
	while (i <= 20)
	{
		if (str[i] == '#')
		{
			if (((i - 1) >= 0) && (str[i - 1] == '#'))
				neighbor++;
			if (((i + 1) <= 19) && (str[i + 1] == '#'))
				neighbor++;
			if (((i - 5) >= 0) && (str[i - 5] == '#'))
				neighbor++;
			if (((i + 5) <= 19) && (str[i + 5] == '#'))
				neighbor++;
		}
		i++;
	}
	return (((neighbor == 6) || (neighbor == 8)));
}

int			ft_addtetrimino(t_list **lst, char *tab, char value)
{
	int		i;
	char	**tableau;
	t_etris	*ret;

	tab = ft_strrep(tab,'\n','.');
	tableau = ft_strsplit(tab, '.');
	ret = tetris_new(tableau,0,0,value);
	ft_lstaddlast(lst,ft_lstnew(ret,sizeof(t_etris)));
	ft_lstaddlast(lst, ft_lstnew(tetris_new(tableau,0,0,value),
			sizeof(t_etris)));
	return (1);
}

t_list		*ft_readfile(int fc)
{
	int		ret;
	char	*tab;
	t_list	**lst;
	char	value;

	lst = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	value = 'A';
	tab = ft_strnew(21);
	while ((ret = read(fc, tab, 21)) > 0)
	{
		ft_putstr(tab);
		if (!(ft_checkneighbor(tab) && ft_checkstring(ret, tab)
				&& ft_addtetrimino(lst,tab,value++)))
		{
			ft_memdel((void **)&tab);
			return (*lst);
		}
	}
	ft_memdel((void **)&tab);
	return (*lst);
}

int		main(int argc, char **argv)
{
	int		fc;
	t_list	*lst;
	int		size;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	fc = open(argv[1], O_RDONLY);
	if (fc == -1)
	{
		ft_putstr("File cannot be read\n");
		return (1);
	}
	if ((lst = ft_readfile(fc)) == NULL)
		close (fc);
	else
	{
		size = ft_findsizemap(lst);
		ft_putstr("reussi\n");
}
