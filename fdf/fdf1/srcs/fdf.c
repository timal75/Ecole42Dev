/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:44:56 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/14 20:34:19 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "fdf.h"

int		main(int argc, char **argv)
{
	t_field		**field;
	t_field		**field_ori;
	t_env		env;
	int			i;
	int			j;

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
	while (i++ < ((*field)->height - 1))
	printf("ds main longueur line %d : %d\n", i, (*field)->line[i].len);
	i = 0;
	while ( i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			ft_putnbr((*field)->line[i].point[j].relief);
			ft_putstr("   ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}

	env.field = field;
	if (!(field_ori = (t_field **)ft_memalloc(sizeof(t_field *))))
		return (1);
	*field_ori = NULL;
	if (!(*field_ori) && !((*field_ori = (t_field *)ft_memalloc(sizeof(t_field)))))
		return (0);
	(*field_ori)->height = (*field)->height;
	i = 0;
	(*field_ori)->line = (t_lines *)ft_memalloc(sizeof(t_lines) * (*field)->height);
	while ( i < ((*field)->height))
	{
		(*field_ori)->line[i].len = (*field)->line[i].len;
		(*field_ori)->line[i].point = (t_point *)ft_memalloc(sizeof(t_point) * (*field)->line[i].len);
		ft_memcpy ((*field_ori)->line[i].point, (*field)->line[i].point, sizeof(t_point) * (*field)->line[i].len);
		i++;
	}
	(*field_ori)->width = (*field_ori)->line[0].len;
	(*field)->width = (*field)->line[0].len;
	env.field_ori = field_ori;

	ft_putendl("****************************************");
	ft_putnbreol((*field_ori)->height);
	i = -1;
	while (i++ < ((*field_ori)->height - 1))
	printf("ds main longueur line ori %d : %d\n", i, (*field)->line[i].len);
	i = 0;
	while ( i < (*field_ori)->height)
	{
		j = 0;
		while (j < (*field_ori)->line[i].len)
		{
			ft_putnbr((*field_ori)->line[i].point[j].relief);
			ft_putstr("   ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	
	
	ft_init_mlx(&env);
	ft_putendl("apres ft_init_mlx");
	mlx_expose_hook(env.window, ft_expose_hook, &env);
	ft_putendl("apres expose_hook");
	mlx_loop(env.mlx);


	return(0);
}
