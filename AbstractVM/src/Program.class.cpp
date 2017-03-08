/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:44:36 by jblancha          #+#    #+#             */
/*   Updated: 2017/02/24 19:17:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.class.hpp"
#include <sstream>



Program::Program(void) :_verbose(false) {}

Program::~Program(void) {}

Program::Program(Program const &program) {	*this=program; }

Program &Program::operator=(Program const &) {	return(*this); }

void Program::setVerbose(bool verbose) { _verbose = verbose; } 

void Program::push(t_command iop) {	_tab.push_back(iop);}

/*t_command Program::pop(void)
{
	if (this->isEmpty())
		throw(Program::SizeEmptyException());
	t_command iop = _tab.at(0);
	_tab.erase(_tab.begin());
	return(iop);
}*/

t_command &Program::last(void)
{
	if (this->isEmpty())
		throw(Program::SizeEmptyException());
	return(_tab.at(_tab.size() - 1));
}

t_command &Program::at(size_t i)
{
	if(i >= _tab.size())
		throw(Program::SizeEmptyException());
	return _tab.at(i);
}

bool Program::verify(void) const
{
TRACER(	std::cout << " Début Program Verify" << std::endl;);
	//if (this->isEmpty())
	//	throw(Program::SizeEmptyException());
	int nboperand = 0;
	for (unsigned int i=0;i<_tab.size();i++)
	{
		t_command program = _tab.at(i);
TRACER( 	std::cout << "command " << program.commande << " / stack with "<< nboperand << " operand(s) " << std::endl; ); 
		
		if (program.commande == "push"){
			nboperand++;
TRACER( std::cout << "		==> stack : "<< nboperand << " operand(s) " << std::endl; ); 

		}
		if ( (nboperand < 2)
		&&   ( program.commande == "add"
		     || program.commande == "sub" || program.commande == "mul" 
		     || program.commande == "div" || program.commande == "mod" )
		)
		{
TRACER( std::cout << "		==> stack : " << nboperand << " operand(s) ... (nboperand < 2) => throw(Program::SizeEmptyException())" << std::endl;); 
			throw(Program::SizeEmptyException());
			return(false);
		}
		if ( (nboperand < 1) 
		&& ( program.commande == "print" 
			|| program.commande == "assert" 
			|| program.commande == "pop" )
		)
		{
TRACER( std::cout << "		==> stack : " << nboperand << " operand(s) ... (nboperand < 1) => throw(Program::SizeEmptyException())" << std::endl;); 
			throw(Program::SizeEmptyException());
			return(false);
		}
		if (  program.commande == "pop" || program.commande == "add" 
		   || program.commande == "sub" || program.commande == "mul" 
		   || program.commande == "div" || program.commande == "mod"){
			nboperand--;
TRACER( std::cout << "		==> stack : "<< nboperand << " operand(s) " << std::endl;); 

		}
		if (nboperand < 0)
		{
TRACER( std::cout << "		==> stack : " << nboperand << " operand(s)  .... (nboperand < 0) => throw(Program::SizeEmptyException())" << std::endl;); 
			throw(Program::SizeEmptyException());
			return(false);
		}
		
	}
	if (_tab.at(_tab.size() - 1).commande != "exit")
	{
TRACER( std::cout << "		==> stack : " << nboperand << " operand(s) ... last commande != \"exit\" => throw(Program::NoExitException())" << std::endl;); 
		throw(Program::NoExitException());
		return(false);
	}
	
TRACER(std::cout << " Verify Successfull\n\n");
	return(true);
}

bool Program::isEmpty(void) const { return(_tab.empty()); }

size_t Program::getSize(void) const { return(_tab.size()); }



Program::NotInt8Exception::NotInt8Exception( std::string const & stackstring, int stacktype)
{
	std::ostringstream ss;
	
	ss << "Not Int8 Exception : "
		<< "stackstring:" << stackstring
		<< ", stacktype:" << stacktype;
	
	_msg = ss.str();
}
Program::NotInt8Exception::NotInt8Exception(Program::NotInt8Exception const &ex) : AVMException(ex), _msg(ex._msg) { *this = ex; }
Program::NotInt8Exception::~NotInt8Exception() throw () {}
Program::NotInt8Exception &Program::NotInt8Exception::operator=(Program::NotInt8Exception const &) { return *this; }
const char * Program::NotInt8Exception::what(void) const throw() { return _msg.c_str(); }

Program::SizeEmptyException::SizeEmptyException(void) {}
Program::SizeEmptyException::SizeEmptyException(SizeEmptyException const &ex) : AVMException(ex) { *this = ex; }
Program::SizeEmptyException &Program::SizeEmptyException::operator=(
		SizeEmptyException const &)  {	return (*this); }
Program::SizeEmptyException::~SizeEmptyException(void) throw () {}
const char * Program::SizeEmptyException::what(void) const throw () {
	return "Exception : Size is empty.";
}


Program::NoExitException::NoExitException(void) {}
Program::NoExitException::NoExitException(NoExitException const &ex) : AVMException(ex) {	*this = ex; }
Program::NoExitException &Program::NoExitException::operator=(Program::NoExitException const &) { return *this; }
Program::NoExitException::~NoExitException(void) throw () {}
const char * Program::NoExitException::what(void) const throw () {
	return "Exception : No Exit command at the end of program.";
}

