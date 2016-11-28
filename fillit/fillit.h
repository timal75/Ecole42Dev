/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:30:06 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 15:33:27 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;
typedef struct	s_etris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_etris;
t_list			*read_tetri(int fd);
t_etris			*tetris_new(char **pos, int width, int height, char c);
#endif
