/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:30:25 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/22 23:00:32 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrice(t_env *env)
{
	ft_matrice_scale(env);
	ft_matrice_rotate(env);
	ft_matrice_trans(env);
}

void	ft_matrice_scale(t_env *env)
{
	t_field		**field;
	t_field		**field_ori;
	int			i;
	int			j;

	field = env->field;
	field_ori = env->field_ori;
	i = 0;
	while (i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			field(i, j).x = field_ori(i, j).x * env->scale;
			field(i, j).y = field_ori(i, j).y * env->scale;
			field(i, j).z = field_ori(i, j).z * 1.0;
			j++;
		}
		i++;
	}
}

void	ft_matrice_trans(t_env *env)
{
	t_field		**field;
	t_field		**field_ori;
	int			i;
	int			j;

	field = env->field;
	field_ori = env->field;
	i = 0;
	while (i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			field(i, j).x = field_ori(i, j).x + env->dx;
			field(i, j).y = field_ori(i, j).y + env->dy;
			field(i, j).z = field_ori(i, j).z + env->dz;
			j++;
		}
		i++;
	}
}

void	ft_matrice_rotate(t_env *env)
{
	t_field		**field;
	t_field		**field_ori;
	int			i;
	int			j;

	field_ori = env->field;
	field = env->field;
	i = 0;
	while (i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			field(i, j).x = cosy * (sinz * field(i, j).y + cosz *
					field(i, j).x) - siny * field(i, j).z;
			field(i, j).y = sinx * (cosy * field(i, j).z + siny *
					(sinz * field(i, j).y + cosz * field(i, j).x)) +
					cosx * (cosz * field(i, j).y - sinz * field(i, j).x);
			field(i, j).z = cosx * (cosy * field(i, j).z + siny *
					(sinz * field(i, j).y + cosz * field(i, j).x))
				+ sinx * (cosz * field(i, j).y - sinz * field(i, j).x);
			j++;
		}
		i++;
	}
}
