/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:30:01 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/03 22:31:18 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int		main(void)
{
	t_point	point;
	set_point(&point);
	return (0);
}
