/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:26:06 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/10 22:43:22 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

void	ft_addContact(Contact *cont, int i)
{
	std::string		buf;

	std::cout << "Please Enter Contact First Name : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 0);
	std::cout << "Please Enter Contact Last Name : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 1);
	std::cout << "Please Enter Contact Nickname : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 2);
	std::cout << "Please Enter Contact Login : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 3);
	std::cout << "Please Enter Contact Postal Adress : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 4);
	std::cout << "Please Enter Contact Email Adress : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 5);
	std::cout << "Please Enter Contact Phone Number : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 6);
	std::cout << "Please Enter Contact Birthday date : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 7);
	std::cout << "Please Enter Contact Favorite Meal : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 8);
	std::cout << "Please Enter Contact Underwear Color : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 9);
	std::cout << "Please Enter Contact Darkest Secret : ";
	std::getline(std::cin,buf) ;
	cont[i].SetContact(buf, 10);
	cont[i].Increasenbcontact();
	std::cout << "\n\n Congratulations. You have successfully added 1 contact in the database.\n";
	std::cout << "You now have " << cont[i].getnbcontact() <<" contact(s) in the database.\n\n";
}

void	ft_listcontactsearch(Contact *cont)
{
	int				i;
	int				j;
	std::string		choice;
	int				exit;

	i = 0;
	j = cont[i].getnbcontact();
	std::cout << std::right << std::setw(10) << "index" << " | ";
	std::cout << std::right << std::setw(10) << "first name" << " | ";
	std::cout << std::right << std::setw(10) << "last name" << " | ";
	std::cout << std::right << std::setw(10) << "nickname" << std::endl;
	while (i < j)
	{
		cont[i].infosearch(i);
		i++;
	}
	i = -1;
	exit = 0;
	std::cout << "\n\nEnter your choice [0" ;
	if (j > 1)
		std::cout <<"-" <<(j-1) <<"]\n";
	else
		std::cout <<"]\n";
	std::cout << "or Press <Enter> to return the main program : ";
	std::getline(std::cin,choice);
	if (choice.length() == 0)
		exit = 1;
	else if (isdigit(choice[0]) && (choice.length() == 1))
	{
		choice = choice.substr(0,1);
		i = stoi(choice);
	}
	while ((i < 0 || i >= j ) && !(exit))
	{
		std::cout << "\n\nYour choice is WRONG!!\n";
		std::cout << "\n\nEnter your choice [0"; 
		if (j > 1)
			std::cout <<"-" <<(j-1) <<"]\n";
		else
			std::cout <<"]\n";
		std::cout << "or Press <Enter> to return the main program : ";
		std::getline(std::cin,choice);
		if (choice.length() == 0)
			exit = 1;
		else if (isdigit(choice[0]) && (choice.length() == 1))
		{
			choice = choice.substr(0,1);
			i = stoi(choice);
		}

	}
	if (!exit)
		cont[i].printinfo();
}

int		main(void)
{
	std::string 	choice;
	Contact			cont[8];
	int				i;

	i = 0;
	while (1 == 1)
	{
		std::cout << "\n\nYou can ADD to the database (ADD)\n";
		std::cout << "You can SEARCH the database (SEARCH)\n";
		std::cout << "You can EXIT the program (EXIT)\n";
		std::cout << "Enter your choice : ";
		std::getline(std::cin,choice);
		std::cout << "\n\n";

		i = cont[i].getnbcontact();
		if (choice == "ADD")
		{
			if (i < 8)
			{
				ft_addContact(cont, i);
			}
			else
				std::cout << "Sorry. Database Contact is FULL!\n\n\n";
		}
		else if (choice == "SEARCH")
		{
			if (i > 0)
			{
				ft_listcontactsearch(cont);
			}
			else
				std::cout << "Sorry. Database Contact is EMPTY!\n\n\n";
		}
		else if (choice == "EXIT")
		{
			std::cout << "Nice doing Business with you! BYE!!\n\n\n";
			break;
		}
		else
		{
			std::cout << choice << std::endl;
			std::cout << "Wrong choice !! Try again!! \n\n\n";
		}
	}
	return (0);
}
