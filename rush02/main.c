/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:44:22 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/17 22:33:16 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define BUF_SIZE 4096 
#include <stdlib.h>
#include <header.h>

int		getnbcolonnes(char	*str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = str;
	while(*str1 != '\0' && *str1 != '\n')
	{
		i++;
		str1++;
	}
    return (i);
}

int		getnblignes(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = str;
	while(*str1 != '\0')
    {
		if (*str1 == '\n')
		{
        	i++;
		}
        str1++;
    }
	    return (i);
}

char	*ft_get_stdin(void)
{
	int		ret;
	int		total_size;
	char	buf[BUF_SIZE + 1];
	char	*final;
	char	tmp[100000];

	total_size = 0;
	final = malloc(1);
	while ((ret = read(0, buf, BUF_SIZE)) > 0)
	{
		ft_strcpy(tmp, final);
		buf[ret] = '\0';
		total_size = total_size + ret;
		final = (char *)malloc(sizeof(char) * total_size);
		final = ft_strcat(tmp, buf);
	}
	return (final);
}
int		main(void)
{
	char	*input;
	char	*str;
	int		nb_col;
	int		nb_lignes;

	input = ft_get_stdin();
	nb_col = getnbcolonnes (input);
	printf("nb colonnes : %d\n",nb_col);
	nb_lignes = getnblignes(input);
	printf("nb lignes : %d\n",nb_lignes);
	str = colle00 (nb_lignes, nb_col);
	if (ft_strcmp (input, str) == 0)
		printf("colle 00\n");
	else
		printf("perdu  00\n");
	return (nb_lignes);
}
