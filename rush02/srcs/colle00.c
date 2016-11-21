/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikacumi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 16:04:18 by ikacumi           #+#    #+#             */
/*   Updated: 2016/09/04 21:48:16 by mlamoure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print(int h, int v, int x, int y)
{
	if ((h == 0 && v == 0) || (h == x - 1 && v == y))
		ft_putchar('o');
	else if ((h == x - 1 && v == 0) || (h == x && v == y - 1))
		ft_putchar('o');
	else if (v == y - 1 && h == 0)
		ft_putchar('o');
	else if (h == x - 1 && v == y - 1)
		ft_putchar('o');
	else if (v == 0 || v == y - 1)
		ft_putchar('-');
	else if (h == 0 || h == x - 1)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	colle(int x, int y)
{
	int h;
	int v;

	while (v < y)
	{
		while (h < x)
		{
			print(h, v, x, y);
			h++;
		}
		ft_putchar('\n');
		h = 0;
		v++;
	}
}
