/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:39:44 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/06 21:56:14 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_getcolor(t_point *point, char *str)
{
	char	*pos;
	int		len;

	if (!(pos = ft_strchr(str, ',')))
		point->color = 0;
	else
	{
		point->color = 1;
		pos = pos + 1;
		len = ft_strlen(pos);
		if (len >= 4)
			point->b = ft_convertcolor(pos[2], pos[3]);
		if (len >= 6)
			point->g = ft_convertcolor(pos[4], pos[5]);
		if (len >= 8)
			point->r = ft_convertcolor(pos[6], pos[7]);
	}
}

int			ft_convertcolor(char c, char d)
{
	return (16 * ft_decimal(c) + ft_decimal(d));
}

int			ft_decimal(char d)
{
	if (d == 'A')
		return (10);
	else if (d == 'B')
		return (11);
	else if (d == 'C')
		return (12);
	else if (d == 'D')
		return (13);
	else if (d == 'E')
		return (14);
	else if (d == 'F')
		return (15);
	else
		return (d - '0');
}

void		ft_lightpoint(t_point point, t_env *env)
{
	int			i;

	if ((point.y >= 0 && point.y < IMG_HEIGHT)
			&& (point.x >= 0 && point.x < IMG_WIDTH)
			&& !(point.y <= 230 && point.x <= 400))
	{
		printf("lightpoint %d,  %d\n", point.x, point.y);
		i = (point.y * env->s_lines) + (point.x * (env->bpp / 8));
		env->data_adress[i] = point.r;
		env->data_adress[++i] = point.g;
		env->data_adress[++i] = point.b;
	}
}
