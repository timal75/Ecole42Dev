/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 21:56:31 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/20 21:17:26 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.Class.hpp"

int main(void)
{
	Span 	sp(7);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return(0);
}
