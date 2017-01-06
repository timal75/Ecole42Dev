/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:37:51 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/27 20:33:11 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_lightpixel(t_point point, t_env *env, int color)
{
	int			i;

	if ((point.y >= 0 && point.y < IMG_HEIGHT)
			&& (point.x >= 0 && point.x < IMG_WIDTH)
			&& !(point.y <= 230 && point.x <= 400))
	{

		i = (point.y * env->s_lines) + (point.x * (env->bpp / 8));
		env->data_adress[i] = color;
		env->data_adress[++i] = color >> 8;
		env->data_adress[++i] = color >> 16;
	}
}

int			ft_get_color(t_point point_ori, t_point point_des)
{
	int			color;

	color = 0xFF6666;
	if ((point_ori.relief > 0) || (point_des.relief > 0))
		color = 0x33FF66;
	if ((point_ori.relief < 0) || (point_des.relief < 0))
		color = 0x33FFFF;
	return (color);
}

void		ft_init_point(t_field **field, t_point *point, int i, int j)
{
	point->x = ((*field)->line[i].point[j].x);
	point->y = ((*field)->line[i].point[j].y);
	point->relief = (*field)->line[i].point[j].relief;
	point->z = (*field)->line[i].point[j].z;
	point->color = (*field)->line[i].point[j].color;
	point->r = (*field)->line[i].point[j].r;
	point->g = (*field)->line[i].point[j].g;
	point->b = (*field)->line[i].point[j].b;
}

int			ft_exist(int i, int j, t_field **field)
{
	if ((i < (*field)->height) && (j < (*field)->line[i].len))
		return (1);
	return (0);
}

void		ft_draw_field(t_field **field, t_env *env)
{
	int			i;
	int			j;
	t_point		point_ori;
	t_point		point_des;

	i = -1;
	while (++i < (*field)->height)
	{
		j = -1;
		while (++j < (*field)->line[i].len)
		{
			if ((ft_exist(i, j, field)) && (ft_exist(i, j + 1, field)))
			{
				ft_init_point(field, &point_ori, i, j);
				ft_init_point(field, &point_des, i, j + 1);
				ft_plotline(env, point_ori, point_des);
			}
			if ((ft_exist(i, j, field)) && (ft_exist(i + 1, j, field)))
			{
				ft_init_point(field, &point_ori, i, j);
				ft_init_point(field, &point_des, i + 1, j);
				ft_plotline(env, point_ori, point_des);
			}
		}
	}
}
