/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 23:00:49 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/15 23:04:47 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 10
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "header.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_strcmp(char *s1, char *s2);
int		ft_get_size(char *filename);
int		ft_atoi(char *str);
int		ft_check_badname(char *avi);
void	ft_put_filename(int ac, char *avi, int *cpt);
int		ft_strlen(char *str);
void	ft_tail(int ac, char *avi, int size, int *cpt);
void	ft_swap(int *a, int *b);
int		ft_atoi(char *str);
void	ft_putnbr(int a);

#endif
