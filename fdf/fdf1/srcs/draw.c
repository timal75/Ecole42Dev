/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:37:51 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/23 00:12:08 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_lightpixel(t_point point, t_env *env, int color)
{
	int			i;

	if ((point.y >= 0 && point.y < IMG_HEIGHT)
			&& (point.x >= 0 && point.x < IMG_WIDTH))
	{
		i = (point.y * env->s_lines) + (point.x * 4);
		ft_putnbreol(i);
		env->data_adress[i] = color;
		env->data_adress[++i] = color >> 8;
		env->data_adress[++i] = color >> 16;
	}
}

int			ft_get_color(t_point point_ori, t_point point_des)
{
	int			color;

	color = 0xFF6666;
	if (point_ori.relief > 0)
		color = 0x33FF66;
	if (point_ori.relief == point_des.relief && point_ori.relief > 0)
		color = 0x33FF66;
	return (color);
}

void		ft_init_point(t_field **field, t_point *point, int i, int j)
{
	point->x = ((*field)->line[i].point[j].x + 1);
	point->y = ((*field)->line[i].point[j].y + 1);
	point->relief = (*field)->line[i].point[j].relief;
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
			if (j < ((*field)->line[i].len) - 1)
			{
				ft_init_point(field, &point_ori, i, j);
				ft_init_point(field, &point_des, i, j + 1);
				ft_plotline(env, point_ori, point_des);
			}
			if (i < ((*field)->height - 1))
			{
				ft_init_point(field, &point_ori, i, j);
				ft_init_point(field, &point_des, i + 1, j);
				ft_plotline(env, point_ori, point_des);
			}
		}
	}
}
