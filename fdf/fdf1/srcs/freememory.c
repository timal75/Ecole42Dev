/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freememory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 22:04:55 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/22 23:17:53 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
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
}
