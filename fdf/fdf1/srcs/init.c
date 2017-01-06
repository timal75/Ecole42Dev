/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 21:22:50 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/22 23:15:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_param_matrice(t_env *env)
{
	env->scale = scale_w > scale_h ? scale_h : scale_w;
	env->scale = env->scale > 5 ? env->scale : 5;
	env->scalez = ft_reliefscale(env);
	env->xcenter = XCENTER;
	env->ycenter = YCENTER;
	env->dx = (IMG_WIDTH / 2) - (((*env->field)->width) / 2 * env->scale);
	env->dy = (IMG_HEIGHT / 2) - (((*env->field)->height) / 2 * env->scale);
	env->xalpha = -40;
	env->alphax = (-40.0f * M_PI) / 180.0f;
	env->yalpha = 0;
	env->alphay = (0.0f * M_PI) / 180.0f;
	env->zalpha = -40;
	env->alphaz = (-40.0f * M_PI) / 180.0f;
	env->dz = 0;
}

int			ft_init_mlx(t_env *env)
{
	ft_init_param_matrice(env);
	ft_createwindow(env);
	return (0);
}

int			ft_copyfield(t_env *env)
{
	t_field		**field_ori;
	t_field		**field;
	int			i;

	field = env->field;
	field_ori = env->field_ori;
	i = 0;
	(*field_ori)->line = (t_lines *)ft_memalloc(sizeof(t_lines)
						* (*field)->height);
	while (i < ((*field)->height))
	{
		(*field_ori)->line[i].len = (*field)->line[i].len;
		(*field_ori)->line[i].point = (t_point *)ft_memalloc(sizeof(t_point)
									* (*field)->line[i].len);
		if (!((*field_ori)->line[i].point))
			return (-1);
		ft_memcpy((*field_ori)->line[i].point, (*field)->line[i].point,
									sizeof(t_point) * (*field)->line[i].len);
		i++;
	}
	(*field_ori)->width = (*field_ori)->line[0].len;
	(*field)->width = (*field)->line[0].len;
	return (0);
}

int			ft_init_field(t_env *env, t_field **field)
{
	int			i;
	t_field		**field_ori;

	env->field = field;
	if (!(field_ori = (t_field **)ft_memalloc(sizeof(t_field *))))
		return (-1);
	env->field_ori = field_ori;
	*field_ori = NULL;
	if (!(*field_ori) && !((*field_ori = (t_field *)
							ft_memalloc(sizeof(t_field)))))
		return (-1);
	(*field_ori)->height = (*field)->height;
	if ((i = ft_copyfield(env) == -1))
		return (-1);
	return (0);
}

int 		ft_init_tab(t_env *env)
{
	int 		i;
	int 		j;

	env->tab = (int **)ft_memalloc(sizeof(int *) * (IMG_WIDTH + 1));
	if (!env->tab)
		return (-1);
	i = 0;
	while (i < (IMG_WIDTH + 1))
	{
		env->tab[i] = (int *)ft_memalloc(sizeof(int) * (IMG_HEIGHT + 1));
		if (!env->tab[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i < (IMG_WIDTH + 1))
	{
		j = 0;
		while (j < (IMG_HEIGHT + 1))
		{
			env->tab[i][j] = -999999999;
			j++;
		}
		i++;
	}
	return (0);
}
