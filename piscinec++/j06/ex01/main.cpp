/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 21:23:52 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/18 22:31:30 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <string>
#include <iostream>
#include <ctime>

static char randomValue()
{
	char	random;

	while (true)
	{
		random = rand() % (0-127);
		if ((random < 91 && random > 64) || (random > 96 && random < 123))
			return(random);
	}
}

void *serialize(void)
{
	char    *part1 = new char[sizeof(char) * 8 * 2 + sizeof(int)];
	char    *part3 = part1 + 8 * sizeof(char) + sizeof(int);
	int     *part2 = reinterpret_cast<int*>(part1 + 8 * sizeof(char));

	for (size_t i = 0; i < 8; i++)
	{
		part1[i] = randomValue();
		part3[i] = randomValue();
	}
	*part2 = std::rand();
	return (part1);

}
Data *deserialize(void *raw)
{
	char    *part1 = reinterpret_cast<char*>(raw);
    int     *part2 = reinterpret_cast<int*>(part1 + 8 *sizeof(char));
    char    *part3 = part1 + 8 * sizeof(char) + sizeof(int) ;
    Data    *dat = new Data;

    dat->s1.resize(8);
    dat->s2.resize(8);
    for (size_t i = 0; i < 8; i++)
    {
	    dat->s1[i] = part1[i];
		dat->s2[i] = part3[i];
    }
   dat->n = *part2;
   return (dat);
}

int main (void)
{
	srand(time(NULL));
	void	*raw;
	Data	*data;

	srand(time(NULL));
	raw = serialize();
	data = deserialize(raw);
	std::cout << "FULLBUFFER:   " << reinterpret_cast<char*>(raw) << std::endl;
	std::cout << "S1:           " << data->s1 << std::endl;
	std::cout << "S2:                     " << data->s2 << std::endl;
	std::cout << " N:                   " << data->n << std::endl;
	delete reinterpret_cast<char*>(raw);
	delete data;
	return (0);
}
