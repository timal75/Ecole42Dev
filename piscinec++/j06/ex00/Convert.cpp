/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:19:06 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/18 21:18:57 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string input) : _input(input) ,_ischar(false),_isint(false),_isdouble(false), _isfloat(false)
{
}

Convert::~Convert()
{
}

void Convert::to_char()
{
	int    v;
	double x;

	if ((this->_input.length()) > 1)
		this->_ischar = false;
	else
	{
		if (this->_input[0] >= '0' && this->_input[0] <= '9')
			v = std::stoi(this->_input.c_str());
		else
		{
			this->_char = this->_input[0];
			this->_ischar = true;
			v = static_cast<int>(this->_input[0]);
		}
		this->setint(v);
		x = static_cast<double>(v);
		this->setdouble(x);
		this->setfloat(static_cast<float>(x));
	}
}

void Convert::setchar(char c)
{
	this->_char = c;
	this->_ischar = true;
}

void Convert::setint(int c)
{
	this->_int = c;
	this->_isint = true;
}

void Convert::setdouble(double c)
{
	this->_double = c;
	this->_isdouble = true;
}

void Convert::setfloat(float c)
{
	this->_float = c;
	this->_isfloat = true;
}

void Convert::to_int()
{
	int    v;
	double x;

	if (this->_input.find('.') == std::string::npos 
			&& (this->_input.size () > 1)
		   	&& (this->_input[this->_input.size()-1] !='f')
		   	&& (this->_input[this->_input.size()-1] !='n'))
	{
		this->_isint = true;
		v = std::stoi(this->_input.c_str());
		x = static_cast<double>(v);
		this->setdouble(x);
		this->setfloat(static_cast<float>(x));
		this->setint(v);
		if (v > 32 && v < 127)
		{
			char c; 
			c = static_cast<char>(v);
			this->setchar(c);
		}
	}
}

void Convert::to_double()
{
	int    v;
	double d;


	if (this->_input.find('.') != std::string::npos 
			&& this->_input[this->_input.size() -1] != 'f')
	{
		this->_isdouble = true;
		d = std::atof(this->_input.c_str());
		this->_double = d;
		this->setfloat(static_cast<float>(d));
		v = static_cast<int>(d);
		this->setint(v);
		if (v > 32 && v < 127)
		{
			char c; 
			c = static_cast<char>(v);
			this->setchar(c);
		}
	}
	else if ((this->_input[this->_input.size() -1] == 'f') 
			|| (this->_input[this->_input.size() -1] == 'n'))
	{
		d = std::atof(this->_input.c_str());
		this->setdouble(d);
		this->setfloat(static_cast<float>(d));
	}	
}

void Convert::to_float()
{
	int    v;
	double d;
	float  f;

	if (this->_input.find('.') != std::string::npos 
			&& this->_input[this->_input.size()-1] == 'f')
	{
		this->_isfloat = true;
		d = std::atof(this->_input.c_str());
		f = static_cast<float>(d);
		this->_float = f;
		this->setdouble(d);
		v = static_cast<int>(d);
		this->setint(v);
		if (v > 32 && v < 127)
		{
			char c; 
			c = static_cast<char>(v);
			this->setchar(c);
		}
	}
}

void Convert::print (void)
{
	this->to_char ();
	this->to_int ();
	this->to_double ();
	this->to_float();
	std::cout << "char: ";
	std::cout.precision (1);
    if (this->_ischar)
		std::cout << this->_char << std::endl;
	else if (isinf(this->_float) || isnan(this->_float))
		std::cout << "Impossible " << std::endl;
	else 
		std::cout << "Not dislayable " << std::endl;
	std::cout << "int: ";
    if (this->_isint)
		std::cout << this->_int << std::endl;
	else if (isinf(this->_float) || isnan(this->_float))
		std::cout << "Impossible " << std::endl;
	else
		std::cout << "Not dislayable " << std::endl;
	std::cout << "float: ";
    if (this->_isfloat)
		std::cout << std::fixed << this->_float << 'f'<<std::endl;
	else
		std::cout << "Not dislayable " << std::endl;
	std::cout << "double: ";
    if (this->_isdouble)
		std::cout << std::fixed << this->_double << std::endl;
	else
		std::cout << "Not dislayable " << std::endl;
}
