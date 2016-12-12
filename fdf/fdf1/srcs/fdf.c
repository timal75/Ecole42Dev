/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:44:56 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/12 22:45:56 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"

int			ft_push_point(int x, int y, int relief, t_field **field)
{
	t_point		*point;
	t_point		*temppoint;

	if (!(point = (t_point *)ft_memalloc(sizeof(t_point))))
		return (0);
	(*point).x = x;
	(*point).y = y;
	(*point).relief = relief;
	
	temppoint = NULL;
	if (!(temppoint) && (temppoint = (t_point *)ft_memalloc(sizeof(t_point) * (y + 1))))
		return (0);
	ft_memmove(temppoint, (*field)->line->point, sizeof((*field)->line->point));
	free((*field)->line->point);
	(*field)->line->point = temppoint;
	(*field)->line[x].point[y] = *point;
	(*field)->line[x].len = y;
	
	free(point);
	return (1);

}

int			ft_push_line(t_field **field, char **line, int height)
{
	char		**tab;
	int			i;
	t_lines		*tmpline;

	if (!(tab = (char **)ft_memalloc(sizeof(char *))))
		return (0);
	if (!(*field) && !((*field = (t_field *)ft_memalloc(sizeof(t_field)))))
		return (0);
		tmpline = (t_lines *)ft_memalloc(sizeof(t_lines) * (height + 1));
		if (height != 0)
		{
			ft_memmove(tmpline,(*field)->line, sizeof((*field)->line));
			free((*field)->line);
		}
		(*field)->line = tmpline;
		(*field)->height = height;
	tab = ft_strsplit(*line, ' ');
	i = 0;
	while (tab[i])
	{
		ft_push_point(height, i, ft_atoi(tab[i]), field);
		i++;
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free (tab);
	return (1);
}
t_field		**ft_read_file(char	*filename)
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
	if ((fd = open(filename,O_RDONLY)) == -1)
		return (NULL);
	height = 0;
	while (((ret = get_next_line(fd,line)) > 0)
			&& ((ft_push_line(field, line, height) ==  1)))
			height++;
	close(fd);
	free (line);
	return (field);
}

int		main(int argc, char **argv)
{
	//t_env		env;
	t_field		**field;
	int			i;

	if (argc != 2)
	{
		ft_putendl("./fdf <file_name>");
		return (0);
	}
	if ((field = ft_read_file(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	ft_putnbreol((*field)->height);
	i = -1;
	while (i++ < (*field)->height)
		ft_putnbreol((*field)->line[i].len);
	return(0);
}
