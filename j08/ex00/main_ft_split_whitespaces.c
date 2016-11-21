/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:39:20 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/09 16:36:31 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		**create_tableau(char **tab, char *str)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			nb_words++;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
	}
	tab = (char**)malloc(sizeof(*tab) * (nb_words + 1));
	tab[nb_words] = 0x0;
	return (tab);
}

char		**create_chaque_mot(char **tab, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
		{
			tab[j] = (char*)malloc(sizeof(**tab) * (k + 1));
			j++;
			k = 0;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
		k++;
	}
	return (tab);
}

char		**fill_tableau(char **tab, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		tab[j][k] = str[i];
		i++;
		k++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			tab[j][k] = '\0';
			j++;
			k = 0;
			while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
				i++;
		}
	}
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;

	tab = NULL;
	tab = create_tableau(tab, str);
	tab = create_chaque_mot(tab, str);
	tab = fill_tableau(tab, str);
	return (tab);
}

int		main(void)
{
	char	*phrase = " n  y name \tis hello  \nworld";
	char	**table = ft_split_whitespaces(phrase);
	int		j;
	int		k;

	j = 0;
	k = 0;
	printf("%s\n", phrase);
	while (j <= 6)
	{
		while (table[j][k] != '\0')
		{
			write(1, &table[j][k], 1);
			k++;
		}
		printf("\n");
		k = 0;
		j++;
	}
	return (0);
}
