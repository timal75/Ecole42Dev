/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legende.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 22:32:10 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/29 22:32:35 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 


void	ft_legende(t_env *e)
{
	ft_legende_cmd(e);
	ft_legende_pos(e);
	ft_legende_rot(e);
	ft_legende_scale(e);	
}


void	ft_legende_cmd (t_env *e)
{
	char	*str;

	str = "fleches : translations de la map";
	mlx_string_put(e->mlx, e->window, 5, 5, 0x708D23, str);
	str = "souris : deplacer la map";
	mlx_string_put(e->mlx, e->window, 5, 20, 0x708D23, str);
	str = "+/- : zoomer / dezoomer";
	mlx_string_put(e->mlx, e->window, 5, 35, 0x708D23, str);
	str = "pageup/pagedown : +/- relief";
	mlx_string_put(e->mlx, e->window, 5, 50, 0x708D23, str);
	str = "touche 1/touche 2 : +/- rotation axe x";
	mlx_string_put(e->mlx, e->window, 5, 65, 0x708D23, str);
	str = "touche 4/touche 5 : +/- rotation axe y";
	mlx_string_put(e->mlx, e->window, 5, 80, 0x708D23, str);
	str = "touche 7/touche 8 : +/- rotation axe z";
	mlx_string_put(e->mlx, e->window, 5, 95, 0x708D23, str);
	str = "clear : reset";
	mlx_string_put(e->mlx, e->window, 5, 110, 0x708D23, str);
	str = "echap : quitter";
	mlx_string_put(e->mlx, e->window, 5, 125, 0x708D23, str);

}

void	ft_legende_pos(t_env *e)
{
	char	*str;

	str = "Position x : ";
	mlx_string_put(e->mlx, e->window, 5, 155, 0x87E990, str);
	str = ft_itoa(e->dx);
	mlx_string_put(e->mlx, e->window, 140, 155, 0x00FFFF, str);
	free(str);
	str = "y : ";
	mlx_string_put(e->mlx, e->window, 185, 155, 0x87E990, str);
	str = ft_itoa(e->dy);
	mlx_string_put(e->mlx, e->window, 225, 155, 0x00FFFF, str);
	free(str);
}

void	ft_legende_scale(t_env *e)
{
	char	*str;

	str = "scale : ";
	mlx_string_put(e->mlx, e->window, 5, 185, 0x87E990, str);
	str = ft_itoa(e->scale);
	mlx_string_put(e->mlx, e->window, 80, 185, 0x00FFFF, str);
	free(str);
	str = "scale z : ";
	mlx_string_put(e->mlx, e->window, 120, 185, 0x87E990, str);
	str = ft_itoa(e->scalez);
	mlx_string_put(e->mlx, e->window, 220, 185, 0x00FFFF, str);
	free(str);
}

void	ft_legende_rot(t_env *e)
{
	char	*str;

	str = "Rotation x : ";
	mlx_string_put(e->mlx, e->window, 5, 170, 0x87E990, str);
	str = ft_itoa(e->xalpha % 360);
	mlx_string_put(e->mlx, e->window, 140, 170, 0x00FFFF, str);
	free(str);
	str = "y : ";
	mlx_string_put(e->mlx, e->window, 190, 170, 0x87E990, str);
	str = ft_itoa(e->yalpha % 360);
	mlx_string_put(e->mlx, e->window, 230, 170, 0x00FFFF, str);
	free(str);
	str = "z : ";
	mlx_string_put(e->mlx, e->window, 270, 170, 0x87E990, str);
	str = ft_itoa(e->zalpha % 360);
	mlx_string_put(e->mlx, e->window, 310, 170, 0x00FFFF, str);
	free(str);
}