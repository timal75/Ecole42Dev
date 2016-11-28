/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 01:58:34 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 02:50:16 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_etris		*tetris_new(char **pos, int width, int height, char value)
{
	t_etris		*tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

int		ft_map_sizelst(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int			ft_maxlst(t_list *lst)
{
		int	max_x;
		int	max_y;
		int	i;
		int	nb_tab;
		
		max_x = 0;
		max_y = 0;
		if (lst)
		{
			while 
		}
}

int			ft_map_size(t_list *lst)
{
	int		sizelst;

	sizelst = ft_map_sizelst(ft_lstcount(lst));
}
