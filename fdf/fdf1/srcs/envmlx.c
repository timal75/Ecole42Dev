/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:37:51 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/22 23:34:17 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_createwindow(t_env *env)
{
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
}

void		ft_createimage(t_env *env)
{
	env->image = mlx_new_image(env->mlx, IMG_WIDTH, IMG_HEIGHT);
	env->data_adress = mlx_get_data_addr(env->image, &(env->bpp),
			&(env->s_lines), &(env->endian));
}

void		ft_destroyimage(t_env *env)
{
	mlx_destroy_image(env->mlx, env->image);
}

void		ft_destroywindow(t_env *env)
{
	ft_freememory(env);
	mlx_destroy_window(env->mlx, env->window);
}
