/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:30:06 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/28 18:48:49 by jblancha         ###   ########.fr       */
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
int         	ft_findsizemap(t_list *lst);
void    		ft_max_size( char *str, int *tab);

int				ft_checkstring(int count, char *str);
void			ft_freetetris(t_etris *tetris);
void			ft_freelst(t_list **lst);
int				ft_checkneighbor(char	*str);
t_etris			*create_maillon(char *str, char value);
int				ft_addtetrimino(t_list **lst, char *tab, char value);
t_list			**ft_readfile(int fc);
void			ft_printmap(t_map *map);
int     		ft_mapsolved(t_map *map, t_list *lst);
#endif
