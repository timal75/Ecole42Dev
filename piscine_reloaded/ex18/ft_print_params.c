/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:53:02 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/05 16:43:45 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	imprime(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	char	c;

	c = '\n';
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			imprime(argv[i]);
			ft_putchar(c);
			i++;
		}
	}
}
