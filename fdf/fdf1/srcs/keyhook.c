/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:30:04 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/23 01:30:07 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_key_hook_trans(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
		e->dy = e->dy - 50;
	if (keycode == KEY_DOWN)
		e->dy = e->dy + 50;
	if (keycode == KEY_RIGHT)
		e->dx = e->dx + 50;
	if (keycode == KEY_LEFT)
		e->dx = e->dx - 50;
	return (0);
}

int			ft_key_hook_rot(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		e->alphax = e->alphax + ((10.0f * M_PI) / 180.0f);
	if (keycode == KEY_2)
		e->alphax = e->alphax - ((10.0f * M_PI) / 180.0f);
	if (keycode == KEY_4)
		e->alphay = e->alphay + ((10.0f * M_PI) / 180.0f);
	if (keycode == KEY_5)
		e->alphay = e->alphay - ((10.0f * M_PI) / 180.0f);
	if (keycode == KEY_7)
		e->alphaz = e->alphaz + ((10.0f * M_PI) / 180.0f);
	if (keycode == KEY_8)
		e->alphaz = e->alphaz - ((10.0f * M_PI) / 180.0f);
	return (0);
}

int			ft_key_hook_scale(int keycode, t_env *e)
{
	if (keycode == KEY_PLUS)
		e->scale = e->scale * 1.2;
	if (keycode == KEY_MINUS)
		e->scale = e->scale / 1.2;
	return (0);
}

int			ft_key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		ft_destroywindow(e);
		exit(0);
	}
	if (keycode == KEY_RESET)
		ft_init_param_matrice(e);
	ft_key_hook_scale(keycode, e);
	ft_key_hook_rot(keycode, e);
	ft_key_hook_trans(keycode, e);
	ft_expose_hook(e);
	return (0);
}
