/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 13:36:41 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/13 18:55:27 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_error(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	if (*argv[2] != '+' && *argv[2] != '-' && *argv[2] != '*'
		&& *argv[2] != '/' && *argv[2] != '%')
	{
		ft_putstr("0\n");
		return (1);
	}
	if (*argv[2] == '/' && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (*argv[2] == '%' && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
}

int		main(int argc, char **argv)
{
	char		*ope;
	pfonc		pf1[5];
	int			i;
	int			retour;

	if (ft_error(argc, argv))
		return (1);
	pf1[0] = ft_add;
	pf1[1] = ft_sub;
	pf1[2] = ft_mul;
	pf1[3] = ft_div;
	pf1[4] = ft_mod;
	ope = "+-*/%";
	i = 0;
	while (i <= 4)
	{
		if (ope[i] == argv[2])
		{
			retour = (*(pf1[i])) (ft_atoi(argv[1]), ft_atoi(argv[3]));
			ft_putnbr(retour);
			ft_putchar('\n');
		}
		i++;
	}
	return (0);
}
