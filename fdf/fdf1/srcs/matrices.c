/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 20:30:25 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/16 20:50:29 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrice(t_env *env)
{
	t_field 	**field;
	t_field 	**field_ori;
	int			i;
	int			j;

	ft_rotate(env);
	field = env->field;
	field_ori = env->field;
	i = 0;
	while ( i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			printf("xo : %d, yo : %d, zo: %d\n", (*field_ori)->line[i].point[j].x, (*field_ori)->line[i].point[j].y ,(*field_ori)->line[i].point[j].z);
			(*field)->line[i].point[j].x = (*field_ori)->line[i].point[j].x * env->scale_w + env->dx;
			(*field)->line[i].point[j].y = (*field_ori)->line[i].point[j].y * env->scale_h + env->dy;
			(*field)->line[i].point[j].z = (*field_ori)->line[i].point[j].z + env->dz;
			printf("xt : %d, yt : %d, zt: %d\n", (*field)->line[i].point[j].x, (*field)->line[i].point[j].y ,(*field)->line[i].point[j].z);
			j++;
		}
		i++;
	}
	ft_putendl("fin matrice transalation");
}

void 	ft_rotate(t_env *env)
{
	t_field 	**field;
	t_field 	**field_ori;
	int			i;
	int			j;
	int 		x;
	int 		y;
	int 		z;

	field_ori = env->field_ori;
	field = env->field;
	
	i = 0;
	while ( i < (*field)->height)
	{
		j = 0;
		while (j < (*field)->line[i].len)
		{
			x = (*field_ori)->line[i].point[j].x;
			y = (*field_ori)->line[i].point[j].y;
			z = (*field_ori)->line[i].point[j].z;
			printf("x : %d, y : %d, z: %d\n", x, y ,z);
			//(*field)->line[i].point[j].y = x * cos(env->alphax) - z * sin(env->alphax)
			(*field)->line[i].point[j].x = x * cos(env->alphay) + z * sin(env->alphay);
			(*field)->line[i].point[j].y = x * sin(env->alphay) * sin(env->alphax) + y * cos(env->alphax) - z * sin(env->alphax) * cos(env->alphay);
			(*field)->line[i].point[j].z = x * cos(env->alphax) * sin(env->alphay)   + y * sin(env->alphax) + z * cos(env->alphay) * cos(env->alphax);
			
			printf("xt : %d, yt : %d, zt: %d\n", (*field)->line[i].point[j].x, (*field)->line[i].point[j].y ,(*field)->line[i].point[j].z);
			j++;
		}
		i++;
	}
	ft_putendl("fin matrice rotation");

}

