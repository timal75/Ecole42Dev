/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:33:30 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/18 23:00:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ctime>

class Base {
public : virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate (void)
{
	int   n;

	n = rand()% 3;

	if (n == 0)
	{
		std::cout << "Generating A class !!\n";
		return (new A);
	}
	if (n == 1)
	{
		std::cout << "Generating B class !!\n";
		return (new B);
	}
	if (n == 2)
	{
		std::cout << "Generating C class !!\n";
		return (new C);
	}
	return(NULL);
}

void identify_from_pointer( Base * p )
{
	try {
			*p = dynamic_cast<A&>(*p);
			std::cout << "A " << std::endl;
		}
		catch (const std::bad_cast&){};
	try {
			*p = dynamic_cast<B&>(*p);
			std::cout << "B " << std::endl;
		}
		catch (const std::bad_cast&){};
	try {
			*p = dynamic_cast<C&>(*p);
			std::cout << "C " << std::endl;
		}
		catch (const std::bad_cast&){};
}

void identify_from_reference( Base &p )
{
	try {
			p = dynamic_cast<A&>(p);
			std::cout << "A " << std::endl;
		}
		catch (const std::bad_cast&){};
	try {
			p = dynamic_cast<B&>(p);
			std::cout << "B " << std::endl;
		}
		catch (const std::bad_cast&){};
	try {
			p = dynamic_cast<C&>(p);
			std::cout << "C " << std::endl;
		}
		catch (const std::bad_cast&){};
}

int main (void)
{
	Base 	*base;
	int		i;

	i = 0;
	srand(time(NULL));
	while (i < 10)
	{
		base = generate();
		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;
		i++;
	}
	return (0);
}
