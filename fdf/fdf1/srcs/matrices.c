/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:30:25 by jblancha          #+#    #+#             */
/*   Updated: 2017/09/13 18:55:33 by jblancha         ###   ########.fr       */
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
			FIELD(i, j).x = FIELD_ORI(i, j).x * env->scale;
			FIELD(i, j).y = FIELD_ORI(i, j).y * env->scale;
			FIELD(i, j).z = FIELD_ORI(i, j).z * env->scalez;
			FIELD(i, j).relief = FIELD_ORI(i, j).relief * env->scalez;
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
			FIELD(i, j).x = FIELD_ORI(i, j).x + env->dx;
			FIELD(i, j).y = FIELD_ORI(i, j).y + env->dy;
			FIELD(i, j).z = FIELD_ORI(i, j).z + env->dz;
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
			FIELD(i, j).x = COSY * (SINZ * FIELD(i, j).y + COSZ *
					FIELD(i, j).x) - SINY * FIELD(i, j).z;
			FIELD(i, j).y = SINX * (COSY * FIELD(i, j).z + SINY *
					(SINZ * FIELD(i, j).y + COSZ * FIELD(i, j).x)) +
					COSX * (COSZ * FIELD(i, j).y - SINZ * FIELD(i, j).x);
			FIELD(i, j).z = COSX * (COSY * FIELD(i, j).z + SINY *
					(SINZ * FIELD(i, j).y + COSZ * FIELD(i, j).x))
				+ SINX * (COSZ * FIELD(i, j).y - SINZ * FIELD(i, j).x);
			j++;
		}
		i++;
	}
}
