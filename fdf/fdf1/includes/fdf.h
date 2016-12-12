/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:00:52 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/12 16:41:38 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "get_next_line.h"

typedef struct		s_point
{
	int				x;
	int				y;
	int				relief;
}					t_point;

typedef struct		s_lines
{
	t_point			*point;
	int				len;
} 					t_lines;

typedef struct		s_field
{
	t_lines			*line;
	int				height;
}					t_field;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
}					t_env;

#endif
