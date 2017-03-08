/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 16:06:10 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/08 21:53:01 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Personne.class.hpp" 
#include "Adulte.class.hpp" 

int main(void)
{

	Personne	pers1("blanchard","Daniel",45);
	Personne	pers2("blanchard","Jean",75);
	Adulte		adul1 ("blanchard","Daniel",45,"Audi", 2, 2017);
	//Personne	pers2("blanchard","Jean",45,"Jaguar", 4, 2015);

	std::cout << "age pers1 est : " << pers1.getage() << std::endl;
	pers1.setage(65);
	std::cout << "age pers1 est : " << pers1.getage() << std::endl;
	std::cout << "age pers2 est : " << pers2.getage() << std::endl;
	pers2.setage(95);
	std::cout << "age pers2 est : " << pers2.getage() << std::endl;
	std::cout << "Nre instance : " << pers1.getnb() << std::endl;
	std::cout << "Nre instance : " << pers2.getnb() << std::endl;



	std::cout << "age  dul1est : " << adul1.getage() << std::endl;
	adul1.setage(65);
	std::cout << "age  dul1est : " << adul1.getage() << std::endl;
	std::cout << "Nre voiture : " << adul1.getnbvoiture() << std::endl;
	std::cout << "Anne : " << adul1.getannee() << std::endl;
	adul1.setannee(1954);
	std::cout << "Anne : " << adul1.getannee() << std::endl;
	return (0);
}
