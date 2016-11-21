/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 13:32:16 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/13 22:47:31 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_H
# define _FT_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);
int		ft_atoi(char *str);
int		ft_add(int i, int j);
int		ft_sub(int i, int j);
int		ft_mul(int i, int j);
int		ft_div(int i, int j);
int		ft_mod(int i, int j);
typedef	int	(*t_fonc)	(int, int);

#endif
