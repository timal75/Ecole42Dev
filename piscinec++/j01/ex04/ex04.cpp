/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:19:46 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 18:27:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main (void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string  &ref = str;

	std::cout << str << std::endl;
	std::cout << ref << std::endl;
	return (0);
}
