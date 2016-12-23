/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:37:51 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/22 23:51:25 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_mouse_hook(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->dx = x;
		env->dy = y;
	}
	if (button == 2)
	{
		env->dx = x;
		env->dy = y;
	}
	ft_expose_hook(env);
	return (0);
}

int			ft_expose_hook(t_env *env)
{
	ft_createimage(env);
	ft_matrice(env);
	ft_draw_field(env->field, env);
	mlx_put_image_to_window(env->mlx, env->window, env->image, 0, 0);
	mlx_key_hook(env->window, ft_key_hook, env);
	mlx_mouse_hook(env->window, ft_mouse_hook, env);
	mlx_destroy_image(env->mlx, env->image);
	return (0);
}
