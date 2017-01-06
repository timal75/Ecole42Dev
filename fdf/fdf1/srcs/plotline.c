/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:22:34 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/06 21:20:16 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_get_line_param(t_line_param *param_line, t_point point_ori,
								t_point point_des)
{
	param_line->dx = ABS(point_des.x - point_ori.x);
	param_line->dy = ABS(point_des.y - point_ori.y);
	param_line->incx = point_des.x < point_ori.x ? -1 : 1;
	param_line->incy = point_des.y < point_ori.y ? -1 : 1;
}

void		ft_penteinf(t_env *env, t_point point_ori, t_point point_des)
{
	t_line_param	param_line;
	int				i;
	t_point			point;

	point.x = point_ori.x;
	point.y = point_ori.y;
	ft_get_line_param(&param_line, point_ori, point_des);
	ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
	param_line.e = (2 * param_line.dy) - param_line.dx;
	param_line.inc1 = 2 * (param_line.dy - param_line.dx);
	param_line.inc2 = 2 * param_line.dy;
	i = 0;
	while (i < param_line.dx)
	{
		if (param_line.e > 0)
		{
			point.y = point.y + param_line.incy;
			param_line.e = param_line.e + param_line.inc1;
		}
		else
			param_line.e = param_line.e + param_line.inc2;
		point.x = point.x + param_line.incx;
		ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
		i++;
	}
}

void		ft_pentesup(t_env *env, t_point point_ori, t_point point_des)
{
	t_line_param	param_line;
	int				i;
	t_point			point;

	point.x = point_ori.x;
	point.y = point_ori.y;
	ft_get_line_param(&param_line, point_ori, point_des);
	ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
	param_line.e = (2 * param_line.dx) - param_line.dy;
	param_line.inc1 = 2 * (param_line.dx - param_line.dy);
	param_line.inc2 = 2 * param_line.dx;
	i = 0;
	while (i < param_line.dy)
	{
		if (param_line.e > 0)
		{
			point.x = point.x + param_line.incx;
			param_line.e = param_line.e + param_line.inc1;
		}
		else
			param_line.e = param_line.e + param_line.inc2;
		point.y = point.y + param_line.incy;
		ft_lightpixel(point, env, ft_get_color(point_ori, point_des));
		i++;
	}
}

void		ft_plotline(t_env *env, t_point point_ori, t_point point_des)
{
	t_line_param	param_line;

	ft_get_line_param(&param_line, point_ori, point_des);
	if (param_line.dx > param_line.dy)
		ft_penteinf(env, point_ori, point_des);
	else
		ft_pentesup(env, point_ori, point_des);
}

int			ft_zbuffer(t_point point, t_env *env)
{
	if ((point.x < (IMG_WIDTH + 1)) && (point.x >= 0)
		&& (point.y < (IMG_HEIGHT + 1)) && (point.y >= 0)
		&& ((point.z >= env->tab[point.x][point.y])
			|| ABS(point.z - env->tab[point.x][point.y]) < 2))
	{
		env->tab[point.x][point.y] = point.z;
		return (1);
	}
	return (0);
}
