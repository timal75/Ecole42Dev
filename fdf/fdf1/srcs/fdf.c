/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:44:56 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/06 22:09:54 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init(t_env *env, t_field **field)
{
	int		ret;

	if ((ret = ft_init_field(env, field)) == -1)
	{
		ft_freememory(env);
		return (-1);
	}
	if ((ret = ft_init_tab(env)) == -1)
	{
		ft_freememory(env);
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_field		**field;
	t_env		env;
	int			ret;

	if (argc != 2)
	{
		ft_putendl("./fdf <file_name>");
		return (1);
	}
	if ((field = ft_read_file(argv[1])) == NULL)
	{
		ft_freefield(field);
		ft_putendl("error");
		return (1);
	}
	if ((ret = ft_init(&env, field)) == -1)
		return (1);
	ft_init_mlx(&env);
	mlx_expose_hook(env.window, ft_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
