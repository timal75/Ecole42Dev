/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freememory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 22:04:55 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/06 21:36:04 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freefield(t_field **field)
{
	int		i;

	i = 0;
	while (i < ((*field)->height))
	{
		if ((*field)->line[i].point)
			free((*field)->line[i].point);
		i++;
	}
	if ((*field)->line)
		free((*field)->line);
	if (*field)
		free(*field);
	if (field)
		free(field);
}

void	ft_freememory(t_env *env)
{
	ft_freefield(env->field);
	ft_freefield(env->field_ori);
	ft_freetab(env);
}

void	ft_freetab(t_env *env)
{
	int		i;

	i = 0;
	while (i < (IMG_WIDTH + 1))
	{
		if (env->tab[i])
			ft_memdel((void **)&env->tab[i]);
		i++;
	}
	if (env->tab)
		ft_memdel((void **)&env->tab);
}

void	ft_relief(t_env *env, t_relief *relief)
{
	t_field		**field;
	int			i;
	int			j;

	field = env->field;
	i = 0;
	relief->max = (*field)->line[0].point[0].relief;
	relief->min = (*field)->line[0].point[0].relief;
	while (i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			if ((*field)->line[i].point[j].relief > relief->max)
				relief->max = (*field)->line[i].point[j].relief;
			if ((*field)->line[i].point[j].relief < relief->min)
				relief->min = (*field)->line[i].point[j].relief;
			j++;
		}
		i++;
	}
}

int		ft_reliefscale(t_env *env)
{
	t_relief	*relief;
	int			scale;

	relief = (t_relief *)ft_memalloc(sizeof(relief));
	ft_relief(env, relief);
	if (relief->max != relief->min)
		scale = env->scale / ((relief->max - relief->min));
	else
		scale = 1;
	free(relief);
	return (scale == 0 ? 1 : scale);
}
