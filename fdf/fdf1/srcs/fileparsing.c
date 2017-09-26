/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:44:56 by jblancha          #+#    #+#             */
/*   Updated: 2017/09/13 16:18:58 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_push_point(int x, int y, char *str, t_field **field)
{
	t_point		*point;
	t_point		*temppoint;
	int			relief;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		return (0);
	relief = ft_atoi(str);
	point->x = y;
	point->y = x;
	point->relief = relief;
	point->z = relief;
	ft_getcolor(point, str);
	if (!(temppoint = (t_point *)ft_memalloc(sizeof(t_point) * (y + 1))))
		return (0);
	if (y != 0)
	{
		ft_memmove(temppoint, (*field)->line[x].point, sizeof(t_point) * y);
		free((*field)->line[x].point);
	}
	temppoint[y] = *point;
	(*field)->line[x].point = temppoint;
	(*field)->line[x].len = y + 1;
	free(point);
	return (1);
}

int			ft_linesplit(t_field **field, int height, char **line)
{
	char		**tab;
	int			i;

	if (!(tab = (char **)ft_memalloc(sizeof(char *))))
		return (0);
	tab = ft_strsplit(*line, ' ');
	i = 0;
	while (tab[i])
	{
		ft_push_point(height, i, tab[i], field);
		i++;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

int			ft_push_line(t_field **field, char **line, int height)
{
	int			i;
	t_lines		*tmpline;

	if (!(*field) && !((*field = (t_field *)ft_memalloc(sizeof(t_field)))))
		return (0);
	tmpline = (t_lines *)ft_memalloc(sizeof(t_lines) * (height + 1));
	if (height != 0)
	{
		ft_memmove(tmpline, (*field)->line, sizeof(t_lines) * height);
		free((*field)->line);
	}
	(*field)->line = tmpline;
	(*field)->height = height + 1;
	i = ft_linesplit(field, height, line);
	return (i);
}

t_field		**ft_read_file(char *filename)
{
	int			fd;
	t_field		**field;
	char		**line;
	int			ret;
	int			height;

	if (!(line = (char **)ft_memalloc(sizeof(char *))))
		return (NULL);
	if (!(field = (t_field **)ft_memalloc(sizeof(t_field *))))
		return (NULL);
	*field = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	height = 0;
	while (((ret = get_next_line(fd, line)) > 0) &&
			((ft_push_line(field, line, height) == 1)))
		height++;
	close(fd);
	if (height == 0)
	{
		free(field);
		field = NULL;
	}
	free(line);
	return (field);
}
