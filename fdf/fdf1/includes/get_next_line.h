/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:44:00 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/12 14:47:33 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h" 
# include "fdf.h" 

typedef struct  s_file
{
		int         fd;
      	char        *buf;
}              t_file;
int get_next_line(const int fd, char **line);
# define BUFF_SIZE 50
# define NEG(x) (((x) < 0) ? 1 : 0)
# define ABS(x) (((x) < 0) ? -(x) : x)

#endif
