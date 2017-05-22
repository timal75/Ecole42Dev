/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:41:25 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/11 23:16:43 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void 	ponyOnTheHeap(int choice)
{
	Pony	*pony;

	std::cout <<"Creating Pony on the heap..\n";
	pony = new Pony("Pony on the heap");
	pony->jump(5);
	if (!choice)
	{
		std::cout <<"Killing Pony on the heap..\n";
		delete(pony);
	}
	std::cout <<"Exiting Pony on the Heap..\n";
}

void 	ponyOnTheStack(void)
{
	Pony	pony("Pony on the stack");

	pony.jump(5);
	std::cout <<"Exiting Pony on the Stack..\n";
}

int	main ()
{
	std::cout <<"Creating Pony on the heap without calling destructor\n\n";
	ponyOnTheHeap(1);
	std::cout <<"\n\nCreating Pony on the heap and calling destructor\n\n";
	ponyOnTheHeap(0);
	std::cout <<"\n\nCreating Pony on the stack\n\n";
	ponyOnTheStack();

	return (0);
}
