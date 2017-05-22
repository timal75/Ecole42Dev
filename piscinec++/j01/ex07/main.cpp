/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 21:31:58 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 22:31:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main (int argc, char **argv)
{
	std::ifstream input(argv[1]);
	std::string output1;
	std::ofstream output;
	std::string line;
	std::string str(argv[2]);
	std::string str1(argv[3]);
	std::string::size_type n = 0;

	if (argc != 4)
	{
		std::cout << "Wrong Number of Inputs !!" << std::endl;
		std::cout <<"usage ./replacestring <filename> <str to be replaced> <str to replace by>\n";
		return (1);
	}
	
	output1 = argv[1];
	output1 += ".replace";
	output.open(output1);
	if (input.is_open())
	{
		while (getline(input, line))
		{
		n = 0; 
		while ( ( n = line.find( str, n ) ) != std::string::npos )
		{
			line.replace( n, str.size(), str1 );
			n += str1.size ();
		}
		 output << line << std::endl;
		
		}
	}
	input.close();
	output.close();
	return (0);
}	
